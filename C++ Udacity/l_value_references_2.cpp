#include <iostream>
using std::cout;
using std::endl;

void myFunction (int &value){
    ++value;
}

int main (){
    int i = 1;
    myFunction (i);
    cout << "i = "<< i << endl;

    return 0;

}