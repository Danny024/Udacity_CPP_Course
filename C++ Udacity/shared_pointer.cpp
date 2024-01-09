#include <iostream>
#include <memory>

using std::shared_ptr;
using std::cout;
using std::endl;

int main(){
    shared_ptr<int> shared1(new int);
    cout<<"shared pointer count = "<<shared1.use_count()<<endl;
    {
        shared_ptr<int> shared2 = shared1;
        cout << "shared pointer count = "<<shared1.use_count() <<endl;
    }

    cout<<"shared pointer count = "<<shared1.use_count()<<endl;



}