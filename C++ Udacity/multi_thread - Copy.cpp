#include <iostream>
#include<vector>
#include <thread>
#include <chrono>
#include <random>

using std::cout;
using std::endl;
using std::vector;
using std::thread;
int main(){
    // Create threads
    vector <thread> threads;
    for (size_t i = 0; i < 10; ++i){
        // Create new thread from a Lambda
        threads.emplace_back([i](){
            // Wait for certain amount of time
            std::this_thread::sleep_for (std::chrono::milliseconds(10 * i));

            // perform work
            cout << "Hello from Work thread #" << i << endl;

        });
    }

    // do something in main ()
    cout << "Hello from Main thread" << endl;

    // call join on all thread object using a range-based loop
    for (auto &t : threads){
        t.join();
    }

    return 0;

}