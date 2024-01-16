#include <iostream>
#include <memory>
using std::shared_ptr;
using std::weak_ptr;
using std::cout;
using std::endl;
int main (){
    shared_ptr <int> mySharedPtr(new int);
    cout<<"shared pointer count = "<<mySharedPtr.use_count()<<endl;

    weak_ptr<int>myWeakPtr1(mySharedPtr);
    weak_ptr<int> myWeakPtr2 (myWeakPtr1);
    cout<<"shared pointer count = "<<mySharedPtr.use_count()<<endl;

    return 0;


}