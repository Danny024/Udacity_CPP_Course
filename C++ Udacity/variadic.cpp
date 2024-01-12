#include <iostream>
#include <thread>
#include <string>
using std::cout;
using std::endl;
using std::string;

void printID (int id){
    std::this_thread::sleep_for (std::chrono::milliseconds(50));
    cout<<"ID = "<<id<<endl;
}

void printIDAndName (int id, string name){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    cout <<"ID = "<< id << ", name = "<<name<<endl;
}

int main (){
    int id = 0; // Define an integer variable

    // Starting threads using variadic templates
    std::thread t1(printID, id);
    std::thread t2(printIDAndName, ++id, "MyString");
    //std::thread t3(printIDAndName, ++id); // this causes a compile error
    
    // wait for threads before returning
    t1.join ();
    t2.join();
    //t3.join();

    return 0;

}