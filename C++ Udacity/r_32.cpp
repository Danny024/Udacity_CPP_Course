#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;
class MyClass{
private:
 int _member;

public:
  MyClass (int val);
  void printVal();

};

// Implemetations 
MyClass::MyClass (int val) :_member(val){}
void MyClass::printVal(){
    cout << " , managed object "<<this<<" with val = "<<_member<<endl;
}
void f(unique_ptr<MyClass>ptr){
    cout <<"unique_ptr "<<&ptr;
    ptr->printVal();
}

int main(){
    unique_ptr<MyClass> uniquePtr = make_unique<MyClass>(23);
    cout <<"unique_ptr "<<&uniquePtr;
    uniquePtr->printVal();
    f(move(uniquePtr));

    if (uniquePtr){
        uniquePtr->printVal();
    }

    return 0;
}