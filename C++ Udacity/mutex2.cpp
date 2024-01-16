#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <mutex>
#include <algorithm>
#include <memory>

using std::cout;
using std::endl;
using std::move;
using std::vector;
using std::mutex;
using std::shared_ptr;
using std::future;
using std::async;
using std::move;

class Vehicle{
    public:
        Vehicle(int id):_id(id) {}
    private:
        int _id;
};

class WaitingVehicles{
    public:
        WaitingVehicles(){}

        //getters/setters
        void printSize(){
            _mutex.lock();
            cout <<"#vehicles = "<<_vehicles.size() <<endl;
            _mutex.unlock();
        }

        // typical behaviour methods
      void pushBack (Vehicle &&v){
        _mutex.lock();
        _vehicles.emplace_back(move(v)); //data race would cause an exception
        _mutex.unlock();
      }
    private:
        vector<Vehicle> _vehicles; // list of all vehicles waiting to enter this intersection
        mutex _mutex;

};

int main(){
    shared_ptr<WaitingVehicles> queue (new WaitingVehicles);
    vector<future<void>> futures;

    for (int i =0; i < 1000; ++i){
        Vehicle v(i);
        futures.emplace_back(async(std::launch::async, &WaitingVehicles::pushBack, queue,move(v)));   

    }
    std::for_each(futures.begin(), futures.end(), [](future<void> &ftr){
        ftr.wait();

    });

    queue->printSize();

    return 0;

}