#include <cmath>
#include <stdexcept>
#include <cassert>
#include <iostream>

using std::cout;
using std::endl;
using std::pow;

class Sphere {

    public :
       static float Volume (float radius);

       Sphere (float radius);
       
    private:
      float _radius;
      static float constexpr _pi {3.14159265358979323846};
      void Validate ();

};


/// Implementation
float Sphere::Volume (float radius){
    return (4.0/3.0 * _pi * pow(radius,3) );
}

Sphere::Sphere(float radius) : _radius(radius){
    Validate ();
}

void Sphere::Validate (){
    if (_radius <0){
        throw std::invalid_argument("Insert only positive values");
    }
}

int main (){
    cout<<"The Sphere of radius 5 has a Volume of "<<Sphere::Volume(5)<<endl;
    return 0;
}