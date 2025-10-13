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
}

union CustomType
{
    float realNum;
    unsigned int intNum;
};


int main()
{
    cout << fixed;
    cout.precision(1);
    CustomType myVar;
    myVar.realNum = 1;
    for (int i = 0; i < 20; ++i)
    {
        cout << i <<" "<< myVar.realNum << " ";
        numToBits(myVar.intNum);
        cout << endl;
        myVar.realNum *= 10;
        
    }
    return 0;
}