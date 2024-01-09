#include <iostream>
#include <thread>

using std::thread;
using std::cout;
using std::endl;

int main (){
    unsigned int nThreads = thread::hardware_concurrency();
    cout<<"This machine supports concurrency with "<<nThreads<<" concurrent threads available"<<endl;
    return 0;


}