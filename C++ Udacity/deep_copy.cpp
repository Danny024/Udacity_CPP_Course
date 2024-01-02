#include <iostream>
/* The Rule of Three States

1. Copy Constructor
2. Copy assignment operator
3. Copy destructor ...
*/
using std::cout;
using std::endl;

class DeepCopy{
    private:
        int *_myInt;
    public:
     DeepCopy(int value);
     ~DeepCopy(); // Copy Destructor
     DeepCopy(const DeepCopy &source); // Copy Constructor ..
     DeepCopy& operator=(const DeepCopy &source); // Copy Assignment Operator ...

};

//Implementation
DeepCopy::DeepCopy (int value){
    _myInt = (int *) malloc (sizeof (int));
    *_myInt = value;
    cout<<" resources have been allocated at address "<<_myInt <<" with a value of "<<*_myInt<<endl;
}

DeepCopy::~DeepCopy() {
    free (_myInt);
    cout<< "resource allocation freed at "<<_myInt<<endl;
}

DeepCopy::DeepCopy (const DeepCopy &source){
    _myInt = (int *) malloc (sizeof (int));
    *_myInt = *source._myInt;
    cout<< "The copy resources have been allocated at address "<<_myInt << " with a value of "<<*_myInt<<endl;
    
}

DeepCopy& DeepCopy::operator=(const DeepCopy &source){
    _myInt = (int *) malloc (sizeof (int));
    cout<< "resources allocated at address "<<_myInt << " with a value of "<<*_myInt<<endl;
    *_myInt = *source._myInt;
    return *this;

}

int main () {
    DeepCopy source (42);
    DeepCopy dest1 (source);
    DeepCopy dest2 = dest1;
}
