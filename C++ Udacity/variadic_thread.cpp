#include <iostream>
#include <thread>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::thread;
using std::move;

void printName (string name, int waitTime){
    std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
    cout << "Name (from Thread) = "<<name << endl;

}

int main (){
    string name1 = "MyThread1";
    string name2 = "MyThread2";

//Starting threads using value-copy and move semantics
   thread t1(printName, name1, 50);
   thread t2 (printName,move(name2), 100 );

   t1.join();
   t2.join();

   //print name from main
   cout<<"Name (from Main) = "<<name1<<endl;
   cout<<"Name (from Main) = "<<name2<<endl;

   return 0;



}
