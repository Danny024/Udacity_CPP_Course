#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <memory>

using std::promise;
using std::future;
using std::cout;
using std::endl;
using std::thread;
using std::move;

void divideByNumber (promise <double> &&prms, double num, double denom){
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work
    try{
        if (denom == 0){
            throw std::runtime_error ("Exception from thread: Divisionby zero!");
        }
        else {
            prms.set_value (num / denom);
        }
    }
    catch (...){
        prms.set_exception(std::current_exception());
    }

}

int main (){
    // create promise and futire
    promise <double> prms;
    future<double> ftr = prms.get_future();

    // start thread and pass promise as argument
    double num = 42.0, denom = 0.0;
    thread t(divideByNumber, move(prms), num, denom);

    // retrieve result within try-catch block
    try{
        double result = ftr.get();
        cout<<"Result = "<<result<<endl;
    }
    catch (std::runtime_error e){
        cout << e.what() << endl;
    }

    // thread barrier
    t.join();

}