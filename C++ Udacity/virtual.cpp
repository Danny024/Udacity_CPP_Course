#include <cmath>
#include <stdexcept>
#include <cassert>
#include <iostream>

using std::pow;
using std::cout;
using std::endl;

//Defining Shape as an Interface
class Shape {
    public :
        // pure virtual function
        virtual float Area () const = 0;
        virtual float Perimeter () const = 0;
               
};

class Rectangle : public Shape {
    public :
        // Getters
        float Area () const override;
        float Perimeter () const override;

        float Length () const;
        float Width () const;

    

        // Constructor
        Rectangle (float width, float length);
            
    private :
        float _width;
        float _length;
        void Validate ();
};

class Circle : public Shape {
    public :
        //Getters
        float Area()const override;
        float Perimeter () const override;
        float Radius ()const;


        // Constructor
        Circle (float radius);
    private :
        float _radius;
        const float pi = 3.14159;
        void Validate ();

};

// Implemenatation
// Rectangle
// Constructor
Rectangle::Rectangle (float width, float length) : _width(width), _length(length) {
    Rectangle::Validate ();
}

float Rectangle::Area () const {
    return (_width * _length);
}

float Rectangle::Perimeter () const {
    return (2 * (_width + _length));
}

// Circle
Circle::Circle (float radius):_radius(radius){
    Circle::Validate ();
}

float Circle::Area () const {
    return (pi * pow(_radius,2));
}

float Circle::Perimeter () const {
    return (2 * pi * _radius);
}

float Circle::Radius () const {
    return _radius;
}

float Rectangle::Length() const {
    return _length;
}

float Rectangle::Width()const{
    return _width;
}

void Rectangle::Validate (){
    if (_width < 0 || _length < 0){
        throw std::invalid_argument ("Please insert a positive number");
    }
}

void Circle::Validate(){
    if (_radius < 0){
        throw std::invalid_argument ("Please insert a positive number");
    }
}

//test
int main (){
    Circle circle (10);
    assert (circle.Radius()==10);
    cout<<"--------------First Test Passed----------\n"<<endl;
    assert (abs(circle.Area()-314.159)<1);
    cout <<"----------------Second Test Passed ------------\n"<<endl;
    assert (abs(circle.Perimeter()-62.832)<1);
    cout <<"-----------------The Third test was Passed----------\n"<<endl;

    Rectangle rectangle (15,10);
    assert (rectangle.Width()==15);
    cout <<"-------------The Fourth Test was passed -----------\n"<<endl;
    assert (rectangle.Length()==10);
    cout<<"-------------The Fifth Test was passed --------\n"<<endl;
    assert (abs(rectangle.Area() - 150) < 1);
    cout <<"-----------The Sixth test was passed ---------\n"<<endl;
    assert(abs(rectangle.Perimeter() - 50) < 1);
    cout <<"-----------------The Seventh Test was Passed--------\n"<<endl;

    //Validity Test
    bool exception {false};
    try {
        Circle invalid_c(-10);
    }
    catch (...){
        exception = true;
    }
    assert (exception);
    cout <<"-------------The Eight Test was Passed ---------------\n"<<endl;

    bool except {false};
    try {
        Rectangle invalid_r (-20,10);
    }
    catch (...){
        except = true;
    }

    assert (except);
    cout <<"----------The Ninth Test was Passed ----------------\n"<<endl;
    return 0;

}
