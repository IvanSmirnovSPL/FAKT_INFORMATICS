#include <iostream>
#include <cstring>

class BadString {
private:
    char* data;
    size_t length;

public:
    // Конструктор
    BadString(const char* str) {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }

    // Деструктор
    ~BadString() {
        delete[] data;
    }

    void print() const {
        std::cout << "String: " << data << ", Address: " << (void*)data << std::endl;
    }
};

int main() {
    BadString str1("Hello");
    str1.print();

    // Поверхностное копирование — оба объекта указывают на одну память!
    BadString str2 = str1;
    str2.print();

    return 0; // При уничтожении str2 и str1 произойдёт двойное удаление одной памяти!
}
