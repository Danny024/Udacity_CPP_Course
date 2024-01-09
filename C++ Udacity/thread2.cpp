#include <iostream>
#include <thread>

using std::thread;
using std::cout;
using std::endl;

void threadFunction(){
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); //simulate
    cout <<"Finished work in thread"<<endl;
}

int main(){
    //Create Thread
    thread t(threadFunction);

    //do something in main()
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    cout<<"Fnished work in main"<<endl;

    // wait for thread to finish
    t.join();

    return 0;

}