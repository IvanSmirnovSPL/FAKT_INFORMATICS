#include<iostream>

// struct Vector2D
// {
//     double x, y;
//     Vector2D(double xVal, double yVal): x(xVal), y(yVal) {}
//     Vector2D operator+ (const Vector2D& v)
//     {
//         return Vector2D{x + v.x, y + v.y};
//     }
// };

template <typename R>
struct Vector2D
{
    R x, y;
    Vector2D(R xVal, R yVal): x(xVal), y(yVal) {}
    Vector2D operator+ (const Vector2D& v)
    {
        return Vector2D{x + v.x, y + v.y};
    }
};


template <typename T>
T sum(T a, T b)
{
    return a + b;
}

template <>
bool sum(bool a, bool b)
{
    std::cout << "I'm bool" << std::endl;
    return a + b;
}

// double sum(double a, double b)
// {
//     return a + b;
// }

// int sum(int a, int b)
// {
//     return a + b;
// }

// Vector2D sum(Vector2D a, Vector2D b)
// {
//     return a + b;
// }

int main()
{
    std::cout << sum(4.0, 5.0) << std::endl;
    std::cout << sum(4, 5) << std::endl;
    std::cout << sum(true, false) << std::endl;
    Vector2D<int> res = sum(Vector2D<int>{1, 2}, Vector2D<int>{3, 4});
    std:: cout << res.x << " " << res.y << std::endl;
}