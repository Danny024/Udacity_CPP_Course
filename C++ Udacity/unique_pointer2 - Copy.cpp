#include <iostream>
#include <memory>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::unique_ptr;

class MyClass {
private:
  string _text;

public:
  MyClass() {}
  MyClass(string text) {_text = text;}
  ~MyClass(){cout<<_text<<" destroyed"<<endl;}
  void setText (string text) {_text = text;}
};

int main (){
    // create unique pointer to proprietary class
    unique_ptr<MyClass> myClass1 (new MyClass());
    unique_ptr<MyClass> myClass2 (new MyClass ("String 2"));

    // Call member function using ->
    myClass1->setText("String 1");
    // use the derefence operator *
    *myClass1 = *myClass2;

    // use the .get() function to retrieve a raw pointer to the object
    cout << "Objects have stack addresses "<<myClass1.get() << " and "<<myClass2.get()<<endl;
    return 0;

}