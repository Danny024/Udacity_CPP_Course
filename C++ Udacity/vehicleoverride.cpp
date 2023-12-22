#include <iostream>
#include <cmath>
#include <cassert>
using std::cout;
using std::endl;
float pi = 3.142;
// Abstract Class / Interface ......
class VehicleModel{
    public :
       virtual void Move (double v, double theta) = 0;
};

class ParticleModel : public VehicleModel {
    public :
        virtual void Move (double v, double theta) override;
        // Getters
        virtual double X() const;
        virtual double Y() const;
        virtual double Theta() const;
    
    private :
        double _x;
        double _y;
        double _theta;
        friend class BicycleModel;

};

class BicycleModel : public ParticleModel{
    public :
        void Move (double v, double theta) override;
        //getter
        double X() const override;
        double Y() const override;
        double Theta() const override;
    
    private :
        double _length {10};
};

// Implementation 
void ParticleModel::Move (double v, double theta) {
    this->_theta += theta;
    this->_x += v * cos(theta);
    this->_y += v * sin (theta); 

}

double ParticleModel::X() const {
    return this->_x;
}

double ParticleModel::Y() const {
    return this->_y;
}

double ParticleModel::Theta() const {
    return this->_theta;
}

void BicycleModel::Move (double v, double theta){
    BicycleModel::_theta += v/_length * tan(theta);
    BicycleModel::_x += v * cos (theta);
    BicycleModel:: _y += v *sin (theta);
}

double BicycleModel::X() const {
    return BicycleModel::_x;
}

double BicycleModel::Y() const {
    return BicycleModel::_y;
}

double BicycleModel::Theta() const {
    return BicycleModel::_theta;
}


// test
int main (){
    ParticleModel particle;
    particle.Move (10.0, pi / 3.0);
    cout << "x is " <<particle.X()<<" y is "<<particle.Y()<<" theta is "<<particle.Theta()<<endl;

    BicycleModel bicycle;
    bicycle.Move (10.0, pi/3.0);
    cout << "x is " <<bicycle.X()<<" y is "<<bicycle.Y()<<" theta is "<<bicycle.Theta()<<endl;
    
    assert (bicycle.Theta()!= particle.Theta());


    return 0;
}


