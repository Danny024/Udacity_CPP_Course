#include <iostream>
#include <thread>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::thread;

void printHello(){
    cout << "Hello from Worker thread #"<<std::this_thread::get_id()<<endl;

}
int main(){
    // Create threads
    vector <thread> threads;
    for (size_t i = 0; i < 5; ++i){
        // Copying thread objects causes a compiler error
        /*
        thread t(printHello);
        threads.push_back(t);
        */
       threads.emplace_back(thread(printHello));
    }

    // do something in main()
    cout<<"Hello from the Main thread #"<<std::this_thread::get_id()<<endl;

    // call join on all thread object using a range-based loop
    for (auto &t: threads){
        t.join();
    }

    return 0;

}