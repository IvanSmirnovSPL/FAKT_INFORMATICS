#include <iostream>

using namespace std;

int main()
{
    int width;
    int height;
    cin >> width >> height;

    float** mat = new float*[height];
    for(int i = 0; i < height; ++i)
    {
        mat[i] = new float[width];
    } 

    mat[height - 1][width - 1] = 100;
    cout << mat[height - 1][width - 1] << endl;

    for(int i = 0; i < height; ++i)
    {
        delete [] mat[i];
    } 
    delete mat;

}