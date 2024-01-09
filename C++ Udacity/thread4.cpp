// trying to ensure the thread function is executed before the main thread
#include<iostream>
#include<thread>

using std::cout;
using std::endl;

void threadFunction(){
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    cout<<"Finished work 1 in thread"<<endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    cout <<"Finished work 2 in thread"<<endl;
}

int main(){
    std::thread t(threadFunction);

    //wait for thread to finish
    t.join();

    //do something in main()
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    cout<<"Finished work 1 in main"<<endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    cout<<"Finished work 2 in main"<<endl;
}