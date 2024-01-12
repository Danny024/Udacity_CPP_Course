#include <iostream>
#include <thread>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::thread;
class Vehicle
{
    public:
        Vehicle():_id(0){}
        void addID(int id){_id = id;}
        void printID(){
             cout<<"Vehicle ID="<<_id << endl;

        }
    private:
        int _id;

};

int main (){
    //Create Thread
    shared_ptr<Vehicle> v(new Vehicle);
    thread t = thread(&Vehicle::addID,v,1); // call member function on object v
    t.join();
    v->printID();

    return 0;



}