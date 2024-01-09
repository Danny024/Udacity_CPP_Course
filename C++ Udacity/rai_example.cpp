#include <iostream>
using std::cout;
using std::endl;
// Resource Is Initialization
 class MyInt {
private:
    int *_p; // pointer to heap data
public:
    MyInt (int *p = NULL){_p = p;}
    ~MyInt (){
        cout<<"resource "<<*_p<<" deallocated"<<endl;
        delete _p;
    }
    int &operator*() {
        return *_p; // overload dereferencing operator
    }

 };
int main (){
    double den[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int length = sizeof(den)/sizeof(den[0]);
    for (size_t i = 0; i < length; ++i){
        // allocate the resources on the stack
        MyInt en(new int(i));
        // use the resource
        cout << *en << "/"<<den[i] << " = "<<*en / den [i]<<endl;


    }
    return 0;

}