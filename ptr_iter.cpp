#include <iterator>
#include <iostream>
#include <vector>

template <typename T>
void dispArray(const T* arr, std::size_t size)
{
    std::cout << "Array:";
    for (std::size_t i = 0; i < size; ++i)
    {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;
}

int main()
{
    std::size_t n;
    std::cin >> n;
    int* arr = new int[n];
    for (std::size_t i = 0; i < n; ++i)
    {
        arr[i] = int(n - i) * 2;
    }
    dispArray(arr, n);
    auto ptr = arr + 1;
    std::cout << "*ptr (= arr + 1): " << *ptr << std::endl;
    std::cout << "type(ptr): " << typeid(ptr).name() << std::endl;
    delete[] arr;

    std::cout << std::endl;

    std::vector<int> stlVector(n);
    std::cout << "Size: " << stlVector.size()
        << ", capacity: " << stlVector.capacity() << std::endl;;
    for (std::size_t i = 0; i < stlVector.size(); ++i)
    {
        stlVector[i] = int(n - i) * 2;
    }
    std::cout << "stlVector: ";
    std::copy(stlVector.begin(), stlVector.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    auto iter = stlVector.begin() + 2;
    std::cout << "*iter (= stlVector.begin() + 2): " << *iter << std::endl;
    std::cout << "type(iter): " << typeid(iter).name() << std::endl;
}