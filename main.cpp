#include <iostream>
#include <fstream>

using namespace std;

class Vector2D
{
public:
    Vector2D(): x(0), y(0) { cout << "Default constructor" << endl; }
    Vector2D(double xVal, double yVal): x(xVal), y(yVal)
    {
        cout << "List constructor" << endl;
    }
    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double xVal)  { x = xVal; }
    void setY(double yVal)  { y = yVal; }

    Vector2D operator + (Vector2D& v)
    {
        return Vector2D{x + v.getX(), y + v.getY()};
    }

    friend ostream& operator << (ostream& out, Vector2D& v)
    {
        return out << "[" << v.x << ", " << v.y << "]";
    }

    friend istream& operator >> (istream& in, Vector2D& v)
    {
        double x;
        double y;
        in >> x >> y;
        v.x = x;
        v.y = y;
        return in;
    }

private:
    double x;
    double y;
};

// ostream& operator << (ostream& out, Vector2D& v)
// {
//     return out << "[" << v.getX() << ", " << v.getY() << "]";
// }

// istream& operator >> (istream& in, Vector2D& v)
// {
//     double x;
//     double y;
//     in >> x >> y;
//     v.setX(x);
//     v.setY(y);
//     return in;
// }

int main(int argc, char const *argv[])
{
    Vector2D v1;
    Vector2D v2();
    Vector2D v3 = {1, 2};
    Vector2D v4 = Vector2D(4, 5);
    Vector2D v5(6, 7);
    Vector2D v6{};
    Vector2D v7{8, 9};

    Vector2D v8;
    cout << v8 << endl;
    cin >> v8;
    cout << v8 << endl;

    Vector2D v9;
    cout << v9 << endl;
    ifstream myFile("test.txt");
    myFile >> v9;
    ofstream myFileOut("test_out.txt");
    myFileOut << v9 << endl;
    myFile.close();

    Vector2D v10 = v9 + v8; 
    cout << v10 << endl;

    return 0;
}
