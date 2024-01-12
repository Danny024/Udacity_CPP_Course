#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <vector>
#include <chrono>

using std::cout;
using std::endl;
using std::vector;
using std::future;
using std::promise;
using std::async;

void workerFunction (int n){
    cout << "Worker thread id = "<< std::this_thread::get_id()<<endl;
    // Perform work
    for (int i = 0; i < n; ++i){
        sqrt(12345.6789);
    }
}

int main(){
    // print system id of worker thread
    cout << "Main thread id = "<<std::this_thread::get_id()<<endl;

    // Start time measurement
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    // Launch various tasks
    vector <future<void>> futures;
    int nLoops = 10, nThreads = 5;
    for (int i =0; i< nThreads; ++i){
        futures.emplace_back(async(workerFunction, nLoops));
    }

    // wait for tasks to complete
    for (const future<void> &ftr : futures){
        ftr.wait();
        //stop time measurement and print execution time
        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 -t1).count();
        cout<<"Execution finished after "<<duration<<" microseconds"<<endl;

        return 0;


    }




}