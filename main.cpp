#include <iostream>

using namespace std;

struct ZooKeeper
{
public:
    ZooKeeper(){}
    ~ZooKeeper() = default;
    static int _animalsNum;
    static void washHands()
    {
        cout << "I wash hands " << _animalsNum << " times!" << endl;
    }
};

int ZooKeeper::_animalsNum = 0;

int main()
{
    ZooKeeper z1{};
    ZooKeeper z2{};

    z1._animalsNum += 1;
    z1.washHands();
    z2.washHands();

    z2._animalsNum += 1;
    z1.washHands();
    z2.washHands();

    return 0;
}