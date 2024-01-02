#include <iostream>
using std::cout;
using std::endl;

class ExclusiveCopy {
private :
    int *_myInt;
public :
    ExclusiveCopy ();
    ~ExclusiveCopy();
    ExclusiveCopy (ExclusiveCopy &source);
    ExclusiveCopy &operator= (ExclusiveCopy &source);
};

ExclusiveCopy::ExclusiveCopy (){
    _myInt = (int *)malloc(sizeof(int));
    cout << "The heap resources has been allocated"<<endl;
}

ExclusiveCopy::~ExclusiveCopy(){
    if (_myInt != nullptr){
        free (_myInt);
        cout << "The heap memory has been freed"<<endl;

    }
}
ExclusiveCopy::ExclusiveCopy (ExclusiveCopy &source){
    _myInt = source._myInt;
    source._myInt = nullptr;
}
ExclusiveCopy& ExclusiveCopy::operator= (ExclusiveCopy &source){
  _myInt = source._myInt;
  source._myInt = nullptr;
  return *this;
}

int main (){
    ExclusiveCopy source;
    ExclusiveCopy destination (source);
    ExclusiveCopy source1;
    ExclusiveCopy destination1 = source1;
}