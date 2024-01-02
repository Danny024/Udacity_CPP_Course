#include <iostream>
using std::cout;
using std::endl;
class SharedCopy {
private :
    int *_myInt;
    static int _cnt;
public:
    SharedCopy(int value);
    ~SharedCopy(); // copy destructor
    SharedCopy (SharedCopy &sources); // Copy Constructor
    
};
int SharedCopy::_cnt = 0;
SharedCopy::SharedCopy (int value){
    _myInt = (int *)malloc(sizeof(int));
    *_myInt = value;
    ++_cnt;
    cout << " Resources allocated at address "<<_myInt << endl;
}

SharedCopy::~SharedCopy (){
    --_cnt;
    if (_cnt == 0){
        free (_myInt);
        cout<<"Resources freed at address "<<_myInt << endl;
    }
    else{
        cout << "Instance at address "<<this << " goes out of scope with _cnt = "<<_cnt<<endl;
    }
}

SharedCopy::SharedCopy (SharedCopy &source){
    _myInt = source._myInt;
    ++_cnt;
    cout << _cnt << " instances with handles to address "<<_myInt <<" with _myInt = "<<*_myInt << endl;

}

int main (){
    SharedCopy source (42);
    SharedCopy destination1 (source);
    SharedCopy destination2 (source);
    SharedCopy destination3 (source);
    return 0;
}