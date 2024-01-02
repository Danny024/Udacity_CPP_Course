#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

class MyClass{
    private : 
       int *_number;
    
    public: 
       MyClass (){
        cout << "Allocate memory"<<endl;
        _number = (int *)malloc (sizeof(int));
       }

       ~MyClass (){
         cout<< "Delete memory"<<endl;
         free (_number);
       }
       void setNumber(int number){
        *_number = number;
        cout << "Number: "<< *_number << endl;
       }

};


int main (){
    //allocate memory using malloc
    // MyClass *myClass = (MyClass *) malloc (sizeof (MyClass));
    // myClass->setNumber(42);
    // free (myClass);

    // allocate memory using new
    MyClass *myClass = new MyClass ();
    myClass->setNumber(42);
    delete myClass;

    return 0;

}