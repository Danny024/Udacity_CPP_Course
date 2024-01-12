#include <iostream>
#include <thread>
#include <future>
#include <string>


using std::string;
using std::promise;
using std::future;
using std::thread;
using std::move;
using std::cout;
using std::endl;

void modifyMessage(promise<string> && prms, string message){
    std::this_thread::sleep_for(std::chrono::milliseconds(4000)); // Simualte Work
    string modifiedMessage = message + " has been modified";
    prms.set_value(modifiedMessage);
}

int main()
{
    //define message
    string messageToThread = "My Message";

    // Create Promise and Future
    promise <string> prms;
    future<string> ftr = prms.get_future();

    // Start thread and pass promise as argument
    thread t(modifyMessage, move(prms), messageToThread);

    // print original message to console
    cout << "Original message from main(): "<<messageToThread << endl;

    //retrieve modified message via future and print to console
    string messageFromThread = ftr.get();
    cout << "Modified message from thread(): "<<messageFromThread<<endl;

    //thread barrier
    t.join();
    return 0;

}