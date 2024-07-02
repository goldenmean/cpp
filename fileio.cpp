#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream fout;
    fout.open("test.txt", ios::out);
    fout << "Hello World again";
    fout.close();
    cout << "File created successfully";
    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;

#include <exception>
/********************************************************************

int main() {
    try {
        ofstream fout("test.txt", ios::out);
        fout << "Hello World again";
        fout.close();
        cout << "File created successfully";
    }
    catch (const ios_base::failure& e) {
        cerr << "File operation failed with exception : " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "An exception occurred: " << e.what() << endl;
    }
    return 0;
}
*********************************************************************/
