#include <iostream>

using namespace std;

int main()
{
    int a = 5; // stack
    int* p = new int; // heap
    *p = 100;
    cout << "a: " << a << endl;
    cout << "*p: " << *p << endl;
    delete p;

    int n;
    cin >> n;
    int* mat = new int[n];
    int* mat2 = new int[n];
    mat[n - 1] = 1;
    //delete [] mat;
}