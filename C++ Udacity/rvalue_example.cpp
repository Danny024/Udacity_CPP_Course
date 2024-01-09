#include <iostream>
using std::cout;
using std::endl;
void myFunction (int && val){
    cout <<"val = "<< val << std::endl;
    
}

int main (){
    myFunction(42);
    return 0;
}