#include <iostream>
#include <thread>
#include <string>
#include <memory>

using std::string;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::thread;
class Vehicle {
    public:
        Vehicle():_id(0) {}
        void addID(int id){
            _id = id;
        }
        void setName(string name){
            _name = name;
        }
        void printID(){
            cout<<"Vehicle ID = "<<_id<<endl;
        }
        void printName(){
            cout<<"Vehicle name = "<<_name<<endl;
        }
    private:
        int _id;
        string _name;

};

int main(){
    // Create thread 1
    shared_ptr<Vehicle> v(new Vehicle);
    thread t1 = thread (&Vehicle::addID,v,1);

    //Create thread 2
    thread t2 = thread (&Vehicle::setName, v,"MyVehicle");

    //wait for thread to finish
    t1.join();
    t2.join();

    //print vehicle id
    v->printID();
    v->printName();

    return 0;

}