#include <cassert>
#include <stdexcept>
#include <iostream>

/*
Encapsulation is the grouping together of data and logic into a single unit. 
In object-oriented programming, classes encapsulate data and functions that operate on that data.
*/

// TODO: Define class Pyramid
// Header File
class Pyramid {
    
// public class members
public :
// constructor
    Pyramid() = default;
    Pyramid(float length, float width, float height);
    
    //Using function overload

// accessors
    float Length() const;
    float Width() const;
    float Height() const;
    float Volume ();
    
// mutators
   void Length(float length);
   void Width(float width);
   void Height (float height);
     
   // public volume function
   float Volume (float length, float width, float height);
    

// private class members
    private :
      float length;
      float width;
      float height;
      float volume;
      void Validate();
};

//Function Implementation  File
Pyramid::Pyramid (float length, float width, float height) : length(length), width(width), height(height){
    Validate ();
}
//Getters Implementation
float Pyramid::Length () const {
    return this->length;   
}
float Pyramid::Width () const {
    return this->width;
}

float Pyramid::Height() const {
    return this->height;
}

float Pyramid::Volume () {
    this->volume = 1.0/3.0 * (this->length * this->width * this->height);
    return this->volume;
}

//Setter Implementation
void Pyramid::Length (float length){
    this->length = length;
    Validate();
}

void Pyramid::Width (float width){
    this->width = width;
     Validate ();
}

float Pyramid::Volume (float length, float width, float height){
    this->length = length;
    this->width = width;
    this->height = height;
    this->volume = 1.0/3.0 * (this->length * this->width * this->height);
    return this->volume;
}
void Pyramid::Validate(){
    if (this->length <= 0 || this->width<=0 || this->height <= 0){
        throw std::invalid_argument(" This argument is Invalid");
    }
}

// Test
int main() {
  Pyramid pyramid(4, 5, 6);
  std::cout << "The volume is "<<pyramid.Volume()<<std::endl;
  assert(pyramid.Length() == 4);
  assert(pyramid.Width() == 5);
  assert(pyramid.Height() == 6);
  assert(pyramid.Volume() == 40);
  std::cout<<pyramid.Volume (3,5,6)<<std::endl;
  std::cout << pyramid.Length()<<std::endl;

  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}
