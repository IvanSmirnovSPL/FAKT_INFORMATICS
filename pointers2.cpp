#include <iostream>

using namespace std;

int main()
{
    int var = 5;
    int* p = &var;
    cout << "Adress: " << p << " , value(*p): " << *p
     << " , value(p[0]): " << p[0] << endl;
    cout << "var: " << var << endl;

    //cout << p[1] << endl;

    int a[10] = {10, 9, 8, 7, 6, 100, 4, 3, 2, 1};
    cout << "Adress (a): " << a << " , value(*a): " << *a <<
    " , value(a[0]): " << a[0] << endl;

    cout << "value( *(a + 5) ): " << *(a + 5) <<
    " , value(a[5]): " << a[5] << endl;
}