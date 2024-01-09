#include  <iostream>
using std::cout;
using std::endl;
int main (){
    int i = 1;
    int j = 2;
    int k = i + j;
    int &&l = i + j;
    

    cout << "k = "<< k << " , l = "<< l << endl;

    return 0;

}