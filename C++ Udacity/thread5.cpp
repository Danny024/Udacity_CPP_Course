#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

void threadFunction(){
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); //simulate work
    cout<<" Finished work in thread\n";

}

int main(){
    //create thread
    thread t(threadFunction);
    // detach thread and continue with main
    t.detach();
    //t.join();

    // do something in main()
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); //simulate work
    cout<<" Finsihed work in main\n";

    return 0;

}