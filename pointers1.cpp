#include <iostream>

using namespace std;

int main()
{
    int a = 5;
    int* p;
    p = &a;
    int b = *p;
    cout << "Adress: " << p << " , value: " << *p << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    a = 6;
    cout << "Adress: " << p << " , value: " << *p << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    *p = 7;
    cout << "Adress: " << p << " , value: " << *p << endl;
    cout << "b: " << b << endl;
    cout << "a: " << a << endl;

    b = 8;
    cout << "Adress: " << p << " , value: " << *p << endl;
    cout << "b: " << b << endl;
    cout << "a: " << a << endl;
}