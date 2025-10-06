#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int field[128][128];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> field[i][j];
        }
    }
    for (int i = 1; i < m; ++i)
    {
        field[0][i] += field[0][i-1];
    }
    for (int j = 1; j < n; ++j)
    {
        field[j][0] += field[j-1][0];
    }

    for (int j = 1; j < n; ++j)
    {
        for(int i = 1; i < m; ++i)
        {
            field[j][i] += field[j - 1][i] < field[j][i - 1] ? field[j - 1][i] : field[j][i - 1];
        }
    }

    int steps[10000];
    int stepsNum = 0;
    int curX = m - 1;
    int curY = n - 1;
    while (!(curX == 0 && curY == 0))
    {
        if (curX > 0)
        {
            if (curY > 0)
            {
                if (field[curY - 1][curX] <= field[curY][curX - 1])
                {
                    steps[stepsNum] = 1;
                    stepsNum ++;
                    curY --;
                }
                else
                {
                    steps[stepsNum] = 2;
                    stepsNum ++;
                    curX --;
                }
            }
            else
            {
                steps[stepsNum] = 2;
                stepsNum ++;
                curX --;
            }
        }
        else
        {
            steps[stepsNum] = 1;
            stepsNum ++;
            curY --; 
        }
    }

    for (int i = stepsNum - 1; i >= 0; --i)
    {
        if (steps[i] == 1)
        {
            cout << "down ";
        }
        else
        {
            cout << "right ";
        }
    }
}