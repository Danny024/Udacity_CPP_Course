#include <iostream>
#include <iostream>
using std::cout;
using std::endl;

class MyMovableClass{
private:
    int _size;
    int *_data;

public:
 MyMovableClass (size_t size); // constructor
 ~MyMovableClass (); //[2]
 
 MyMovableClass &operator=(const MyMovableClass &source); // copy assignment operator [3]
 MyMovableClass (const MyMovableClass &source); // copy constructor [1]
 MyMovableClass (MyMovableClass &&source); // Move constructor  [4]
 MyMovableClass &operator= (MyMovableClass &&source); // [5]
};

// Implementation
MyMovableClass::MyMovableClass (size_t size) {
    _size = size;
    _data = new int [_size];
    cout<<"CREATING instance of MyMovableClass at "<<this << " allocated with size = "<<_size * sizeof (int) << " bytes" << endl;
}

MyMovableClass::~MyMovableClass (){
    cout<<"DELETING instance of MyMovableClass at "<<this<<std::endl;
    delete[] _data;
}

MyMovableClass::MyMovableClass (const MyMovableClass &source){
    _size = source._size;
    _data = new int [_size];
    *_data = *source._data;
    cout << "COPYING content of instance "<<&source << " to instance "<<this<<endl;
}

MyMovableClass& MyMovableClass::operator=(const MyMovableClass &source){
    cout<<"ASSIGNING content of instance "<<&source << " to instance "<< this << endl;
    if (this == &source){
        return *this;
    }
    delete [] _data;
    _data = new int [source._size];
    *_data = *source._data;
    _size = source._size;
    return *this;
}

MyMovableClass::MyMovableClass (MyMovableClass &&source){
    cout<<"MOVING constructor instance "<< &source << " to instance "<<this << endl;
    _data = source._data;
    _size = source._size;
    source._data = nullptr;
    source._size = 0;
}
MyMovableClass& MyMovableClass::operator= (MyMovableClass &&source){
    cout << "MOVING (assign) instance "<<&source << " to instance "<<this <<endl;
    if (this == &source){
        return *this;
    }
    delete[] _data;
    _data = source._data;
    _size = source._size;
    source._data = nullptr;
    source._size = 0;
    return *this;

}

int main(){
    MyMovableClass obj1(10);
    MyMovableClass obj2(obj1);
    obj2 = obj1;

}