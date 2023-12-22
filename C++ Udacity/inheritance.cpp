#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
using std::string;
using std::cout;
using std::endl;


class Vehicle{
    public :
       void Move () const;
       Vehicle () = default;
       Vehicle (int wheels);

       // getter to get wheels
       int Wheels ()const;
       void Wheels (int wheels);

       protected:
          int _wheels;
       private :
        void Validate ();
       
};

class Car : public Vehicle {
    public :
    void Move () const;
    Car () = default;
    Car (int wheels);

};


// Implemantation File
Vehicle::Vehicle (int wheels):_wheels(wheels){
    Validate ();
}

void Vehicle::Validate (){
    if (_wheels <=0){
        throw std::invalid_argument (" Please insert a positive number");
    }
}
//Getter
int Vehicle::Wheels () const {
    return _wheels;
}

//Setter
void Vehicle::Wheels (int wheels){
    _wheels = wheels;
    Validate ();
}


void Vehicle::Move()const {
    cout<<" I am a moving Vehicle "<<endl;

}

Car::Car (int wheels) : Vehicle(wheels){}

void Car::Move()const{
    cout<<" I am a moving Car "<<endl;
}

// Main File 
int main (){
    Vehicle vehicle (3);
    assert (vehicle.Wheels()==3);
    cout<<"--------------1st Test Passed------------- "<<endl;

    Car car (4);
    assert (car.Wheels()==4);
    cout <<" ------------2nd Test passed----------"<<endl;
    cout <<vehicle.Wheels()<<endl;
    cout <<car.Wheels()<<endl;
    car.Move();
    vehicle.Move();
    bool exception {false};
    try {
        Vehicle invalid(-1);
    }catch(...){
        exception = true;
    }
    assert (exception);
    cout<<"----------3rd Test Passed----------"<<endl;
    return 0;
}