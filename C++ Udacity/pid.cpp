// Create a PID controller on Cpp
#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

class PidController {

    public :
       PidController(float kp, float ki, float kd);

       //Getters
       float Kp () const;
       float Ki () const;
       float Kd () const;

       float Control (float set_point, float process_variable);

    private:
        float _kp;
        float _ki;
        float _kd;
        float _prev_error;
        float _integral; 
        void Validate ();    

};


//Implementation
PidController::PidController(float kp, float ki, float kd) : _kp (kp), _ki(ki), _kd(kd),_prev_error(0), _integral(0){
    Validate();
}


void PidController::Validate (){
    if (_kp < 0 || _ki < 0; _kd < 0){
        throw std::invalid_argument (" You cannot insert a negative number");
    }
}


// Defining getters
float PidController::Kp()const {
    return _kp;
}

float PidController::Ki()const {
    return _ki;
}

float PidController::Kd () const {
    return _kd;
}

float PidController::Control(float set_point, float process_variable){
    float error = set_point - process_variable;
    _integral += error;

    float control_output = _kp * error + _ki * _integral + _kd * (error-_prev_error);

    _prev_error = error;

     return control_output;

}


int main (){
    float kp = 0.5;
    float ki = 10;
    float kd = 5;
    
    PidController pid (kp,ki,kd);
    assert (pid.Kp()==0.5);
    assert (pid.Ki()==10);
    assert (pid.Kd()==5);

    cout<<"---------------- The First Test has been Passed--------------"<<endl;
    cout<<" "<<endl;

    float SV = 100;
    float PV = 80;

    for (int i = 0; i < 2; ++i){

        float Output = pid.Control(SV,PV);
        PV += Output;
        cout<<" The process variable is "<< PV<<endl;
        cout<<" "<<endl;

    }
    



    assert (PV==-4005);
    
    cout << "------------The Third test passed correctly------------"<<endl;

}