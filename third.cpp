#include <iostream>

using namespace std;


int main()
{
    cout << fixed;
    cout.precision(1);
    float b = 0;
    float bOld = -1;
    while ((b < 1e36) && (b != bOld))
    {
        bOld = b;
        b += 1;
    }
    cout << b << endl;
    return 0;
}