#include <iostream>

using namespace std;


void show(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int* m = new int[n];
    for (int i = 0; i < n ; ++i)
    {
        m[i] = n - i;
    }
    show(m, n);

    delete [] m;
}