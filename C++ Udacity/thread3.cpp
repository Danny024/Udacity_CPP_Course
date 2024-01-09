#include <iostream>
#include <thread>
using std::cout;
using std::endl;
void threadFunction(){
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate
    cout<<"Finished work 1 in thread"<<endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    cout<<"Finished work 2 in thread"<<endl;
}

int main(){
    //create thread
    std::thread t(threadFunction);

    // do something in main
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    cout<<"Finished work 1 in main"<<endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    cout<<"Finished work 2 in main"<<endl;

    t.join();
    return 0;
}