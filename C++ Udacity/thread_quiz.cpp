#include <iostream>
#include<thread>

using std::cout;
using std::endl;
using std::thread;
void threadFunctionEven(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    cout << "Even thread \n";

}

void threadFunctionOdd (){
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    cout<<"Odd thread\n";
}

int main(){
    for (int i = 0; i < 6; ++i){
        if (i % 2 == 0){
            thread t(threadFunctionEven);
            t.detach();
        }
        else{
            thread t(threadFunctionOdd);
            t.detach();
        }
    }

    //ensure that main does not return before the threads are finished
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work
    cout <<"End of main is reached"<<endl;
}