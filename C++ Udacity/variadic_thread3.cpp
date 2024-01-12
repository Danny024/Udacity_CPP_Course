#include <iostream>
#include <thread>
using std::cout;
using std::endl;
class Vehicle {
public:
    Vehicle():_id(0){}
    void addID(int id){_id = id;}
    void printID(){
        cout << "Vehicle ID="<<_id<<endl;

    }
private:
    int _id;
};

int main (){
    Vehicle v1, v2;
    std::thread t1 = std::thread(&Vehicle::addID, v1, 1); //call member function on object v
    std::thread t2 = std::thread(&Vehicle::addID, &v2, 2); // call member function on object v

    // wait for thread to finish
    t1.join();
    t2.join();

    // print Vehicle id
    v1.printID();
    v2.printID();

    return 0;
}