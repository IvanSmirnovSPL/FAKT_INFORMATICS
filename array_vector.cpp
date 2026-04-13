#include <iostream>

template<typename T, int Size>
class Array {
public:
    Array(): _size(Size) {};
    Array(std::initializer_list<T> l) : _size(Size)
    {
        auto iter = l.begin();
        for (int idx = 0; idx < _size; ++idx)
            _arr[idx] = *iter++;
    }
    ~Array() = default;
    int size() const { return _size; }
    T& operator [] (int idx) { return _arr[idx]; }
private:
    int _size;
    T _arr[Size];
};

template<typename T>
class Vector {
public:
    Vector(): _size(0), _capacity(0) {}
    Vector(int size) : _size(size), _capacity(size) { _arr = new T[_size]; }
    Vector(std::initializer_list<T> l): _size(l.size()), _capacity(l.size())
    {
        _arr = new T[_size];
        int arrIdx = 0;
        for (auto iter = l.begin(); iter != l.end(); ++iter)
        {
            _arr[arrIdx++] = *iter;
        }
    }
    ~Vector() { delete[] _arr; }
    T& operator [] (int idx) { return _arr[idx]; }
    T  operator [] (int idx) const { return _arr[idx]; }
    void push_back(const T& elem)
    {
        if (_size == _capacity)
        {
            if (_size > 0)
            {
                T* tmp = new T[_size];
                for (int idx = 0; idx < _size; ++idx) { tmp[idx] = _arr[idx]; }
                delete[] _arr;
                _capacity = _capacity * 2;
                _arr = new T[_capacity];
                for (int idx = 0; idx < _size; ++idx) { _arr[idx] = tmp[idx]; }
                delete[] tmp;
            }
            else
            {
                _capacity = 1;
                _arr = new T[_capacity];
            }
            _arr[_size++] = elem;
        }
        else
        {
            _arr[_size] = elem;
            ++_size;
        }

    }

    friend std::ostream& operator << (std::ostream& out, const Vector<T>& vec)
    {
        out << "[";
        for (int idx = 0; idx < vec.size(); ++idx)
            out << vec[idx] << ", ";
        out << "]";
        return out;
    }

    int size() const { return _size; }
    int capacity() const { return _capacity; }
private:
    int _size = 1;
    int _capacity = 1;
    T* _arr;
};

int main()
{
    Array<int, 5> myArr = {1, 2, 3, 4, 5};
    myArr[2] = 1;
    std::cout << myArr[2] << std::endl;

    Vector<float> v(5);
    std::cout << "Size: " << v.size() << ", capacity: " << v.capacity() << std::endl;
    v.push_back(1);
    std::cout << "Size: " << v.size() << ", capacity: " << v.capacity() << std::endl;

    Vector<double> w;
    std::cout << "Size: " << w.size() << ", capacity: " << w.capacity() << std::endl;
    w.push_back(1);
    std::cout << "Size: " << w.size() << ", capacity: " << w.capacity() << std::endl;
    w.push_back(10);
    std::cout << "Size: " << w.size() << ", capacity: " << w.capacity() << std::endl;
    w.push_back(100);
    std::cout << "Size: " << w.size() << ", capacity: " << w.capacity() << std::endl;

    Vector<int> u = { 1, 2 };
    std::cout << u << std::endl;
}
