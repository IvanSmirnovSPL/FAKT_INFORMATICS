#include <iostream>

using namespace std;

struct Rectangle
{
    int a;
    int b;
};

int main()
{
    Rectangle myRectangle{1, 2};
    cout << myRectangle.a << " " << myRectangle.b << endl;
    Rectangle* pToRectangle = &myRectangle;
    pToRectangle->a = 5;  
    cout << (*pToRectangle).a << " " << pToRectangle->b << endl;
}
