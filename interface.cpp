#include <iostream>

class Figure
{
public:
    virtual double calcSquare() = 0;
};

class Triangle: public Figure{
public:
    double calcSquare() override { return 1; }
};
class Square: public Figure{
public:
    double calcSquare() override { return 2; } 
};

int main()
{
    Triangle t;
    Square s;
    std::cout << t.calcSquare() << std::endl;
    std::cout << s.calcSquare() << std::endl;
    return 0;
}