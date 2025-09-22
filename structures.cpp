#include <iostream>

using namespace std;

struct Person
{
    unsigned int height;
    char surname[10];
};

int main()
{
    Person man;
    man.height = 175;
    man.surname[0] = 'G';
    man.surname[1] = 'e';
    man.surname[2] = 'v';
    man.surname[3] = 'o';
    man.surname[4] = 'r';
    man.surname[5] = 'g';
    man.surname[6] = '\0';

    cout << "Surname: " << man.surname << ", height: " << man.height << endl;
    return 0;
}