#include <iostream>

using namespace std;

void show(double*  arr, unsigned int size)
{
    for (unsigned int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void setMinusOnes(double*  arr, unsigned int size)
{
    for (unsigned int i = 0; i < size; ++i)
    {
        arr[i] = -1;
    }
}

void expand(
    double** pointer,
    unsigned int curSize,
    unsigned int desiredSize
)
{
    double* curArray = *pointer;
    double* tmp = new double[desiredSize];
    setMinusOnes(tmp, desiredSize);
    for (unsigned int i = 0; i < curSize; ++i)
    {
        tmp[i] = curArray[i];
    }
    delete [] *pointer;
    *pointer = tmp;
}

int main()
{
    double* arr = new double[3];
    setMinusOnes(arr, 3);
    arr[0] = 1;
    arr[1] = 1000;
    show(arr, 3);
    expand(&arr, 3, 10);
    show(arr, 10);



    delete [] arr;

}