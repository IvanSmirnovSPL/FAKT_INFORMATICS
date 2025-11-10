#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int* c = new int;
    int* d = new int[n];
    d[n - 1] = 101;
    cout << d[n - 1] << endl;
    *c = 100;
    cout << c << " " << *c << endl;
    delete c;
    delete [] d;
}