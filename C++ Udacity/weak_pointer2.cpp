#include <iostream>
#include <memory>

using std::shared_ptr;
using std::weak_ptr;
using std::cout;
using std::endl;

int main(){
    shared_ptr<int> mySharedPtr (new int);
    weak_ptr <int> myWeakPtr (mySharedPtr);
    mySharedPtr.reset (new int);
    if (myWeakPtr.expired() == true){
        cout<<"Weak pointer expired!"<<endl;
    }
    return 0;
}