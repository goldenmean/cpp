
#include <iostream>
#include <csignal>
#ifdef _WIN32
#include <Windows.h>
#elif __linux__
#include <unistd.h>
#endif

using namespace std;

void signalHandler( int signum ) {
   cout << "Interrupt signal (" << signum << ") received.\n";

   // cleanup and close up stuff here  
   // terminate program  

   exit(signum);  
}

int main () {
   int i = 0;
   // register signal SIGINT and signal handler  
   signal(SIGINT, signalHandler);  

   while(++i) {
      cout << "Going to sleep...." << endl;
      if( i == 3 ) {
         raise( SIGINT);
      }
      Sleep(1000);
   }

   return 0;
}

