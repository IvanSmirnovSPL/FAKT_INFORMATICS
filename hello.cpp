#include <iostream>
class Shape {
public :
    virtual void draw () const { std :: cout << " Shape \ n " ; }
};

class Circle : public Shape {
public :
    void draw () const { std :: cout << " Circle \ n " ; }
};

void render ( const Shape & s ) {
    s . draw () ;
}

int main () {
    Circle c ;
    render ( c ) ;
}