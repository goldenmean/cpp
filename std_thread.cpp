#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

void print_block(int n, char c) {
    {
        std::unique_lock<std::mutex> locker(mtx);
        for (int i = 0; i < n; ++i) {
            std::cout << c;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::thread t1(print_block, 50, '*');
    std::thread t2(print_block, 50, '$');

    // Make threads detachable so they can continue even after main exits
    t1.detach();
    t2.detach();

    //Wait for the threads to finish if they are not detachable
    //t1.join();
    //t2.join();

    return 0;
}