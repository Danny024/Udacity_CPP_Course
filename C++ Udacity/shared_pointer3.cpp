#include <iostream>
#include <memory>

using std::shared_ptr;
using std::cout;
using std::endl;

class MyClass{
public:
  shared_ptr<MyClass> _member;
  ~MyClass() {cout <<"Destructor of MyClass called"<<endl;}
  
};
int main (){
    shared_ptr<MyClass> myClass1 (new MyClass);
    shared_ptr<MyClass>myClass2 (new MyClass);

    return 0;
}
