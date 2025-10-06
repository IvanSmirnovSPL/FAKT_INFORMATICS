#include <iostream>

using namespace std;

int main()
{
    unsigned long long int n;
    cin >> n;
    unsigned long long int zeroEndCombinations = 1;
    unsigned long long int oneEndCombnations = 1;
    unsigned long long int curLength = 1;
    while (curLength < n)
    {
        unsigned long long int tmp = oneEndCombnations;
        oneEndCombnations = zeroEndCombinations;
        zeroEndCombinations = oneEndCombnations + tmp;
        curLength++;
    }
    cout << zeroEndCombinations + oneEndCombnations << endl;
}