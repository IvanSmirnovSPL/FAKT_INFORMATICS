#include <iostream>
using namespace std;


int main()
{
    long int n, m;
    long int arr[1000], arr2[1000];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> m;

    int minValue = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < minValue)
        {
            minValue = arr[i];
        }
    }

    for (int j = 0; j < m; j++)
    {
        int curMaxValue = arr[0];
        int idxMaxValue = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > curMaxValue)
            {
                curMaxValue = arr[i];
                idxMaxValue = i;
            }
        }
        
        arr2[m-j - 1] = curMaxValue;
        arr[idxMaxValue] = minValue;
    }

    for (int j = 0; j < m; j++)
    {
        cout << arr2[j] << " ";
    }


    return 0;
}