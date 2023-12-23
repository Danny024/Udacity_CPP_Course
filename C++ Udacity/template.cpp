// generic programming
// A generic code is one that is independent of type

#include <iostream>
#include  <cassert>
using std::cout;
using std::endl;


template <typename Type>
Type Sum (Type a, Type b){
   return a + b;
}

template <typename T>
T Product (T a, T b){
    return a * b;
}

int main (){
    assert (Sum <double> (4,5)==9);
    assert (Product<int>(5,5)==25);
    cout<<Sum <double> (4,5)<<endl;
    cout <<Product<int>(5,5)<<endl;
    
}