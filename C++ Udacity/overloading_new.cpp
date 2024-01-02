#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

class MyClass {
    private :
        int _mymember;
    
    public :
        MyClass(){
            cout << "Constructor is called"<<endl;

        }

        ~MyClass(){
            cout<<"Destructor is Called"<<endl;
        }

        void *operator new (size_t size)
        {
            cout << "new: Allocating "<< size << "bytes of memory"<< endl;
            void *p = malloc (size);
            return p;
        }

        void operator delete (void *p){
            cout << "delete: Memory is freed again "<<endl;
            free (p);
        }

};

int main ()
{
    MyClass *p = new MyClass();
    delete p;
}