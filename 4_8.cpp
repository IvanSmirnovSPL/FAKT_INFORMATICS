#include <iostream>
using namespace std;


int main()
{
    int mat[100][100];
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    int idxMaxColumn = 0;
    int maxColumnSum = 0;
    for (int i = 0; i < n; i++)
    {
        maxColumnSum += mat[i][0];
    }

    for (int j = 0; j < m; j++)
    {
        int curColumnSum = 0;
        for (int i = 0; i < n; i++)
        {
            curColumnSum += mat[i][j];
        }
        if (curColumnSum > maxColumnSum)
        {
            maxColumnSum = curColumnSum;
            idxMaxColumn = j;
        }
    }

    cout << idxMaxColumn << endl;


    return 0;
}