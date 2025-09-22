#include <iostream>
using namespace std;


int main()
{
    long int tPlan[100], tReal[100];
    long int F, N, M, D;
    cin >> F >> N >> M >> D;
    for (int i = 0; i < N; i++)
    {
        cin >> tPlan[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> tReal[i];
    }

    int taskNumber = 0;
    for (int i = 0; i < N; i++)
    {
        if (F > tPlan[i] && F > 0)
        {
            F = F - tReal[i];
            if (tReal[i] > tPlan[i])
            {
                F = F - D;
            }
            if (tReal[i] < tPlan[i])
            {
                F = F + M;
            }
            taskNumber ++;
        }
        else
        {
            break;
        }
    }

    cout << taskNumber << endl;

    return 0;
}