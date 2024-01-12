#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

class Vehicle{
    public:
        void operator()(){
            cout<<"Vehicle object has been created \n"<<endl;
            
        }

};

int main(){
    //thread t(Vehicle()); // C++'s most vexing parse
    // How to fix thus
    std::thread t1 ( (Vehicle())); // Add an extra pair of parentheses
    std::thread t2 = std::thread(Vehicle()); // Use copy initialization
    std::thread t3 {Vehicle()}; // Use uniform initialization with braces
    cout <<"Finished work in main \n";

    t1.join();
    t2.join();
    t3.join();

    return 0;

}