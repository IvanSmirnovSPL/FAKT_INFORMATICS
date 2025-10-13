#include <iostream>

using namespace std;

void numToBits(unsigned int num)
{
    char arr[32];
    unsigned int mask = 1;
    for (int i = 0; i < 32; i++)
    {
        arr[i] = (unsigned int)(num & mask) > 0 ? '1' : '0';
        mask = mask << 1;
    }
    for (int i = 31; i >= 0; --i)
    {
        cout << arr[i];
    }
    cout << endl;
}

union CustomType
{
    float realNum;
    unsigned int intNum;
};


int main()
{
    CustomType myVar;
    cin >> myVar.realNum;
    numToBits(myVar.intNum);
    return 0;
}