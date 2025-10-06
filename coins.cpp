#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int tenCoins = n / 10;
    n -= tenCoins * 10;
    int fiveCoins = n / 5;
    n -= fiveCoins * 5;
    int oneCoins = n;
    cout << tenCoins << " " << fiveCoins << " " << oneCoins << endl;
}