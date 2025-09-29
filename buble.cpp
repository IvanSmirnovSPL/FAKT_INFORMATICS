#include <iostream>

using namespace std;

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubleSort(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main()
{
    int arr[5] = {3, 2, 8, 1, 5};
    printArr(arr, 5);
    bubleSort(arr, 5);
    printArr(arr, 5);
    return 0;
}