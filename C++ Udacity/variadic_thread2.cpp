#include <iostream>
#include <thread>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::ref;
void printName (string &name, int waitTime){
    std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
    name += " (from Thread)";
    cout<<name<<endl;

}

int main(){
    string name ("MyThread");
    // starting thread
    std::thread t(printName, ref(name), 50);

    //wait for thread before returning
    t.join();

    // print name from main
    name += "(from Main)";
    cout << name << endl;

    return 0;
}