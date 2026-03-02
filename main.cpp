#include <iostream>

using namespace std;

int main()
{
    cout << "Hi!" << endl;

    int a = 5;
    int b = 6;

    const int c = 0;

    const int * p0 = &a; // *p0 = 3; не пройдёт, p0 = &b; пройдёт
    int * const p1 = &a; // *p1 = 3; пройдёт, p1 = &b; не пройдёт
    const int * const p2 = &a; // *p2 = 3; не пройдёт, p2 = &b; пройдёт

    const int& abc = a;

    return 0;
}