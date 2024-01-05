#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

class MyMovableClass {
private:
    int _size;
    int *_data;
public:
    MyMovableClass(size_t size);

    ~MyMovableClass ();
    
    MyMovableClass (const MyMovableClass &source);
    MyMovableClass &operator= (const MyMovableClass &source); // copy assignment operator

};

// Implementation 
MyMovableClass::MyMovableClass (size_t size){
    _size = size;
    _data = new int [_size];
    cout << "CREATING instance of MyMovable Class at "<<this<<" allocated with size = "<<_size * sizeof(int)<<" bytes"<<endl;

}

MyMovableClass::~MyMovableClass(){
    cout<<"DELETING instance of MyMovable at "<<this<<endl;
    delete [] _data;
}

MyMovableClass::MyMovableClass (const MyMovableClass &source){
    _size = source._size;
    _data = new int [_size];
    *_data = *source._data;
    cout << "COPYING Content of Instance "<< &source << " to instance "<<this<<endl;
}

MyMovableClass& MyMovableClass::operator= (const MyMovableClass &source){
    cout << "ASSIGNING content of instance "<<this<<endl;
    if (this == &source){
        return *this;
    }
    delete [] _data;
    _data = new int [source._size];
    *_data = *source._data;
    _size = source._size;
    return *this;

}

MyMovableClass createObject (int size){
    MyMovableClass obj (size); // regular constructor
    return obj; // return MyMovableClass Object by Value
}

int main (){
    MyMovableClass obj1(10); //regular constructor
    MyMovableClass obj2 (obj1); // copy constructor
    obj2 = obj1; //copy assignment operator

    MyMovableClass obj3 = obj1; // call to copy constructor (alternate syntax)

    MyMovableClass obj4 = createObject(10);

    MyMovableClass obj5 (createObject(10));

    return 0;
}