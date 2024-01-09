#include <iostream>
using std::cout;
using std::endl;
void myFunction (int &value){
    cout << "val = "<<value << endl;
}

int main (){
    int j = 42;
    myFunction (j);

    myFunction (42);

    int k = 23;
    myFunction (j + k);

    return 0;
}