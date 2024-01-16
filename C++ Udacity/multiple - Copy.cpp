#include <string>
#include <iostream>
#include <cassert>
using std::cout;
using std::string;
using std::endl;
class Sensor{
    public : 
        Sensor () = default;
        Sensor (string name);
        void Name (string name);
        string Name ();
    private :
       string _name;
       friend class EventCamera;

};

class Camera {
    public :
        Camera () = default;
        Camera (string brand);
        void Brand (string brand);
        string Brand ();
    
    private :
        string _brand;
        friend class EventCamera;


};

class EventCamera: public Sensor, public Camera{
    public : 
        EventCamera (string name, string brand);

};

// Function defination
void Sensor::Name (string name){
    _name = name;
    cout<<_name<<endl;
}

void Camera::Brand (string brand){
    _brand = brand;
    cout << _brand<<endl;
}
Camera::Camera (string brand):_brand(brand){}
Sensor::Sensor (string name):_name(name){}

string Sensor::Name(){
    return _name;
}

string Camera::Brand (){
    return _brand;
}

EventCamera::EventCamera (string name, string brand): Sensor(name), Camera(brand){}

int main (){
    Sensor sensor("Lidar");
    Camera camera ("Hukoyo");
    EventCamera event ("Prophesee", "EVK4");
    cout << event.Name()<<endl;
    cout << event.Brand()<<endl;
    assert (event.Name()=="Prophesee");
    assert (event.Brand()=="EVK4");
    return 0;

}