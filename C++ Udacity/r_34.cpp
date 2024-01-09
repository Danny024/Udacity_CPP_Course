#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;

class MyClass{
private:
   int _member;

public:
    MyClass (int val);
    void printVal();
};

// Implementation
MyClass::MyClass(int val) : _member(val){}
void MyClass::printVal(){
    cout <<", managed object "<<this<<" with val = "<<_member<<endl;
}
void f(unique_ptr<MyClass>ptr){
    cout <<"unique_ptr "<<&ptr;
    ptr->printVal();
}

void f(shared_ptr<MyClass> ptr){
    cout <<"shared_ptr (ref_cnt = )"<< ptr.use_count() << ")"<<&ptr;
    ptr->printVal();
}

int main(){
    shared_ptr<MyClass> sharedPtr = make_shared<MyClass>(23);
    cout<<"shared_ptr (ref_cnt= "<<sharedPtr.use_count() <<") "<<&sharedPtr;
    sharedPtr->printVal();
    return 0;

}