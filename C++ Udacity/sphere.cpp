#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>

using std::pow;
using std::cout;
using std::endl;
using std::abs;
 //Header File

 class Sphere {
    public :
     //Constructor 
       Sphere() = default;
       Sphere (float radius);

     // Getters 
       float Radius() const;
       float Volume()const;

     //Setter
       void Radius (float radius);
       float Volume (float radius);
       static float Volume (float radius);

    private :
       static float constexpr pi_ {3.14159265358979323846};
       float _radius;
       void Validate(); 

 };


 // Implementation file

 void Sphere::Validate (){
    if (_radius <= 0){
        throw std::invalid_argument(" This is an invalid argument");
    }
 }
 
 Sphere::Sphere (float radius) : _radius(radius) {
    Validate ();
 }

// Define Getters
 float Sphere::Radius() const {
    return _radius;
 }

 float Sphere::Volume () const {
    return 4.0/3.0 * pi_ * pow(_radius,3);

 }

 // define setter
 void Sphere::Radius (float radius){
    _radius = radius;
    Validate();
 }

float Sphere::Volume(float radius){
    _radius = radius;
    return 4.0/3.0 * pi_ * pow(_radius,3);
    Validate();

}


 // Main File/ test file
 int main (){
    Sphere Egg (5);
    assert (Egg.Radius() == 5 );
    assert (abs(Egg.Volume()-523.598) < 1);

    cout<<"The radius of the first egg is " <<Egg.Radius()<< " with a volume of "<<Egg.Volume()<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout << "Getter Test Passed "<<endl;

    Egg.Volume(10);
    assert (Egg.Radius()==10);
    assert (abs(Egg.Volume()-4188.79) < 1);

    cout <<" "<<endl;
    cout<<"The radius of the second egg is " <<Egg.Radius()<< " with a volume of "<<Egg.Volume()<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout << "First Setter Test Passed "<<endl;

    Egg.Radius(15);
    assert (Egg.Radius()==15);
    assert (abs(Egg.Volume()-14137.17) < 1);

    cout <<" "<<endl;
    cout<<"The radius of the third egg is " <<Egg.Radius()<< " with a volume of "<<Egg.Volume()<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout << "Second Setter Test Passed "<<endl;


    // test for Invariant Rule
    bool exception {false};
    try{
        Sphere invalid (-5);
    }
    catch (...){
         exception = true;
    }
    assert (exception);
    return 0;
 }