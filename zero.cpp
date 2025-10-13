#include <iostream>

using namespace std;

int main()
{
    unsigned int n;
    cin >> n;
    char arr[32];
    unsigned int mask = 1;
    for (int i = 0; i < 32; i++)
    {
        arr[i] = (unsigned int)(n & mask) > 0 ? '1' : '0';
        mask = mask << 1;
    }
    for (int i = 31; i >= 0; --i)
    {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}