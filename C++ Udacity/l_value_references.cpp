#include <iostream>
using std::cout;
using std::endl;
int main ()
{
    int i = 1;
    int &j = i;
    ++i;
    ++j;
    cout<<"i = "<<i<<", j = "<<j<< endl;
    return 0;

}