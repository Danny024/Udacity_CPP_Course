#include <iostream>
#include <thread>
#include <future>
#include <cmath>

using std::promise;
using std::future;
using std::cout;
using std::endl;
using std::thread;
using std::move;
using std::future_status;

void computeSqrt(promise<double> &&prms, int input){
    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // Simulate Work
    double output = sqrt(input);
    prms.set_value(output);
}

int main(){
    // define input data
    double inputData = 42.0;

    // create promise and future
    promise <double> prms;
    future <double> ftr = prms.get_future();

    // Start thread abd pass promise as argument
    thread t(computeSqrt, move(prms), inputData );

    // Student Task start here
    // wait for result to become available
    auto status = ftr.wait_for(std::chrono::milliseconds(3000));

    if (status == future_status::ready){
        cout << "Result = "<<ftr.get() << endl;
    }

    // time out has expired of functions has not yet started
    else if (status == future_status::timeout || status == future_status::deferred){
        cout << "Result unavailable " << endl;
    }
    t.join();
    return 0;

}