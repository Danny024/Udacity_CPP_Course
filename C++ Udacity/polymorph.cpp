#include <string>
#include <cassert>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
class Animal{
    public :
        virtual string Talk () const = 0;

};

class Dog : public Animal {
    public :
        string Talk () const override;

};

class Lion : public Animal {
    public :
        string Talk() const override;

};

// Implememtation 
string Dog::Talk () const {
    return ("Bark!");
}

string Lion::Talk()const{
    return ("Roar!");
}


int main (){
    Dog dog;
    assert (dog.Talk()=="Bark!");
    cout<<"----------------Test Passed----------\n"<<endl;
    Lion lion;
    assert (lion.Talk()=="Roar!");
    cout<<"------------Second Test Passed -----------\n"<<endl;
    return 0;

}


