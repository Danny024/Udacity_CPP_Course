#include <iostream>
#include <cassert>
#include <stdexcept>
#include <string>
using std::string;

/*
Abstraction refers to the separation of a class's interface from the details of its implementation.
 The interface provides a way to interact with an object, while hiding the details and implementation of how the class works.
*/

// Header student.h file
/*
ifndef STUDENT_H
define STUDENT_H
*/
class Student {
    public:
    // Constructor
    Student () = default;
    Student (string name, int grade, float gpa );

    //Using function overload to determine setters and getters

    // Getters
    string Name() const;
    int Grade() const;
    float GPA() const;

    //mutators
    void Name (string name);
    void Grade (int grade);
    void GPA(float gpa);

    private:
    string _name;
    int _grade;
    float _gpa;
    // Invariant Function that sets the rule for setters and constructors ..
    void Validate();

};

//endif


//Implementation File 
//Constructor implementation
Student::Student (string name, int grade, float gpa) : _name(name), _grade(grade),_gpa(gpa){
    Validate ();
} 
void Student::Validate (){
    if (typeid(this->_name) != typeid(std::string) || this->_grade < 0 || this->_grade > 12 || this->_gpa < 0 || this->_gpa > 4.0 ){
        throw std::invalid_argument("This is an Invalid argument");

    }
}

// define Getters
string Student::Name() const {
    return this->_name;
}

int Student::Grade() const {
    return this->_grade;
}

float Student::GPA() const {
    return this-> _gpa;
}

// define Mutators
void Student::Name(string name){
    this->_name = name;
    Validate();
}

void Student::Grade (int grade){
    this->_grade = grade;
    Validate ();
}

void Student::GPA(float gpa){
    this->_gpa = gpa;
    Validate();
}

//Test file 
int main (){
    Student student ("Jimmy", 2, 3.0);
    assert (student.Name()=="Jimmy");
    assert (student.Grade()== 2);
    assert (student.GPA()==3.0);

    bool exception {false};
    try {
        Student invalid ("Jimmy", -1, 5.0);
    }
    catch (...){
        exception = true;
    }
    assert (exception);
    return 0;
}