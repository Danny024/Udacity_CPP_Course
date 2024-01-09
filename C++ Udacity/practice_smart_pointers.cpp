#include <string>
#include <iostream>
#include <memory>
using std::unique_ptr;
using std::string;
using std::shared_ptr;
using std::weak_ptr;
using std::cout;
using std::endl;
using std::make_unique;
using std::make_shared;
using std::move;

void f1 (unique_ptr<string> unique_ptr){
    //print the content of the unique pointer to the terminal
    cout<<*unique_ptr;
}

void f2 (shared_ptr<string> shared_ptr){
    // Task 4 Print the use count property of shared_ptr to the terminal
    if (shared_ptr.use_count()==2){
        cout << *shared_ptr;
    }

}

void f3 (weak_ptr<string> weak_ptr){
    if (auto shared_ptr = weak_ptr.lock()){
        cout<<*shared_ptr<<endl;
    }
    else {
        cout<<"weak pointer is expired"<<endl;
    }
}

int main (){
    auto unique_str = make_unique<string>("Learn ");
    auto shared_str_1 = make_shared<string>("Coding ");
    auto shared_str_2 = make_shared<string>("with Udacity!");

    //Moving a unique pointer to transfer ownership
    f1(move(unique_str));

    // Pass a shared pointer by value
    f2(shared_str_1);

    //Pass a weak ptr by value and create a shared ptr from it to use it
    weak_ptr<string> weak_ptr_1;
    weak_ptr_1 = shared_str_2;
    f3(weak_ptr_1);

    weak_ptr<string>weak_ptr_2;
    {
        auto shared_str_3 = make_shared<string>("without Udacity");
        weak_ptr_2 = shared_str_3;
    }
    f3(weak_ptr_2);
}