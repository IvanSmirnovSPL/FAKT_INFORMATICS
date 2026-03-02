#include <iostream>

using namespace std;

class Vector3D
{
public:
    Vector3D(double x, double y, double z): _x(x), _y(y), _z(z) {}
    Vector3D(): _x(0), _y(0), _z(0) {}
    double x() const { return _x; }
    double y() const { return _y; }
    double z() const { return _z; }

    Vector3D operator + (const Vector3D& v)
    {
        return Vector3D{_x + v.x(), _y + v.y(), _z + v.z()};
    }

    Vector3D operator - (const Vector3D& v)
    {
        return Vector3D{_x - v.x(), _y - v.y(), _z - v.z()};
    }

    double operator * (const Vector3D& v)
    {
        return _x * v.x() + _y *- v.y() + _z* v.z();
    }

    void operator () ()
    {
        cout << "Hi, I'm Vector3D" << endl;;
    }

    Vector3D cross (const Vector3D& v)
    {
        return Vector3D{
            _y - v.y() - _z * v.z(),
            _z - v.z() - _x * v.x(),
            _x - v.x() - _y * v.y()
        };
    }

    friend std::ostream& operator << (std::ostream& out, const Vector3D& v)
    {
        return out << "[" << v._x << ", " << v._y << ", " << v._z << "]";
    }
private:
    double _x, _y, _z;
};



int main()
{
    Vector3D v0{};
    cout << v0 << endl;
    Vector3D v1{1, 2, 3};
    Vector3D v2{1, 2, 3};
    cout << v1 << endl;
    cout << v2 << endl;
    Vector3D v3 = v1 + v2;
    cout << v3 << endl;
    cout << v3 * v1 << endl;
    cout << v3.cross(v1) << endl;
    v3();

    return 0;
}