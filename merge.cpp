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

void mergeSort(int *arr, int size)
{
    if (size == 2)
    {
        if (arr[1] < arr[0])
        {
            int tmp = arr[1];
            arr[1] = arr[0];
            arr[0] = tmp;
        }
    }
    if (size > 2)
    {
        int leftSize = size / 2;
        int rightSize = size - leftSize;
        int *leftArr = new int[leftSize];
        int *rightArr = new int[rightSize];
        for (int i = 0; i < leftSize; i++)
        {
            leftArr[i] = arr[i];
        }
        for (int i = 0; i < rightSize; i++)
        {
            rightArr[i] = arr[i + leftSize];
        }
        mergeSort(leftArr, leftSize);
        mergeSort(rightArr, rightSize);
        int leftPointer = 0;
        int rightPointer = 0;
        for (int i = 0; i < size; i++)
        {
            if (leftPointer < leftSize)
            {
                if (rightPointer < rightSize)
                {
                    if (leftArr[leftPointer] < rightArr[rightPointer])
                    {
                        arr[i] = leftArr[leftPointer];
                        leftPointer++;
                    }
                    else
                    {
                        arr[i] = rightArr[rightPointer];
                        rightPointer++;
                    }
                }
                else
                {
                    arr[i] = leftArr[leftPointer];
                    leftPointer++;
                }
            }
            else
            {
                arr[i] = rightArr[rightPointer];
                rightPointer++;
            }
        }
    }
}


int main()
{
    int arr[5] = {3, 2, 8, 1, 5};
    printArr(arr, 5);
    mergeSort(arr, 5);
    printArr(arr, 5);
    return 0;
}