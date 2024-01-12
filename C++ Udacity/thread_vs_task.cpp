#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <memory>

using std::future;
using std::promise;
using std::async;
using std::cout;
using std::endl;

double divideByNumber (double num, double denom)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work
    if (denom == 0){
        throw std::runtime_error ("Exception from thread: Division by zero!");
   
    }
    return num / denom;
}

int main(){
    //use async to start a task
    double num = 42.0, denom = 2.0;
    future<double> ftr = async (divideByNumber, num, denom);

    // retrieve result within try-catch block
    try {
        double result = ftr.get();
        cout << "Result = "<<result<<endl;
    }
    catch (std::runtime_error e)
    {
        cout<<e.what()<<endl;

    }

}