#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
using std::string;
using std::cout;
using std::endl;
class Animal {
    protected :
       string _color;
       int _age;
       string _name;
    
    public :
      Animal(string color, int age, string name);
      Animal () = default;
      //Getters
    string Color () const;
    int Age ()const;
    string Name () const;

    //Define Setters
    void Color (string color);
    void Age (int age);
    void Name (string name);

};

class Snake : public Animal {
    private :
       int _length;
      
    public : 
       Snake (string color, int age, string name);
       Snake () = default;
       void MakeSound()const;

};

class Cat : public Animal {
    private :
     int _height;
     
     public : 
       Cat (string color, int age, string name);
       Cat () = default;
       void MakeSound()const;

};

// Implementation 
string Animal::Color ()const{
    return _color;
}
int Animal::Age() const {
    return _age;
}
string Animal::Name ()const {
    return _name;
}

void Animal::Color(string color){
    _color = color;
}

void Animal::Age(int age){
    _age = age;
}

void Animal::Name(string name){
    _name = name;
}

Animal::Animal (string color, int age, string name):_color(color),_age(age),_name(name){}
Snake::Snake (string color,int age, string name){
    this->_color = color;
    this-> _age = age;
    this-> _name = name;

}
Cat::Cat (string color,int age, string name){
    this->_color = color;
    this-> _age = age;
    this-> _name = name;
}

void Snake::MakeSound()const{
    cout<<"Hiss"<<endl;

}

void Cat::MakeSound()const{
  cout<<"Meow "<<endl;
}

int main (){
    Cat cat ("Yellow", 12, "Garfield");
    assert (cat.Name()=="Garfield");
    assert (cat.Color()=="Yellow");
    assert (cat.Age()==12);
    cout<<"Test Passed "<<endl;
    Snake snake ("Black", 17, "Garfield");
    cat.MakeSound();
    snake.MakeSound();


}

