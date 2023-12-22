class Shape {
public :
    virtual float Area () const = 0;
    virtual float Perimeter () const = 0;
};

class Rectangle : public Shape {
    public :
    float Area () const {
        

    }
    
    private :
     float _width;
     float _length;
};