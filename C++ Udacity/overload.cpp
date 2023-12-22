#include <iostream>
using std::cout;
using std::endl;
class Dog {};
class Cat {};
class Goat {};

class Animal{
    public:
    void makeSound (Dog dog);
    void makeSound (Cat cat);
    void makeSound (Goat goat);

};

//Definition
void Animal::makeSound (Dog dog){
    cout<<"bark "<<endl;
}

void Animal::makeSound(Cat cat){
    cout<<"Meow "<<endl;
}

void Animal::makeSound (Goat goat){
    cout<<" Mow "<<endl;
}

int main (){
    Animal animal;
    animal.makeSound(Goat());
    animal.makeSound (Cat());
    animal.makeSound (Dog());
    return 0;
}