#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 4


void *PrintHello(void *threadid) 
{
   long tid;
   //tid = *(long*)threadid;
   //cout << "Hello World! Thread ID, " << tid << endl;
   cout << "Hello World! Thread " << std::flush << endl;
   
   //pthread_detach(pthread_self()); // Detach the current thread

   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   int rc;
   int i;
   
   for( i = 0; i < NUM_THREADS; i++ ) {
      cout << "main() : creating thread, " << i << std::flush << endl;
      rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
      
      if (rc) {
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL);
}