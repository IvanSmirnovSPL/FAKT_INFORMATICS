#include <iostream>
using namespace std;


struct Vector {
    int x, y, z;
};


Vector sum(Vector a, Vector b)
{
    return Vector{a.x + b.x, a.y + b.y, a.z + b.z};
}

int main()
{
    Vector first = {1, 2, 3};
    Vector second{4, 5, 6};
    Vector res = sum(first, second);

    cout << "[" << res.x << ", " << res.y << ", " << res.z << "]" << endl;

    return 0;
}