#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[1000];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    int price;
    cin >> price;
    int curCoinNum = 0;
    int coinsInHand = 0;
    while (price > 0 && curCoinNum < n)
    {
        if (price - arr[curCoinNum] >= 0)
        {
            price -= arr[curCoinNum];
            coinsInHand++;
        }
        curCoinNum++;
    }
    if (curCoinNum == n)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << coinsInHand << endl;
    }
}