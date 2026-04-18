#include <string>
#include <iostream>

/*
Правило трёх
Суть: если классу нужен один из трёх специальных методов, скорее всего, понадобятся и остальные два:

 - деструктор;

 - конструктор копирования;

 - оператор присваивания копированием.

Причина: по умолчанию C++ выполняет поверхностное копирование (shallow copy) — просто копирует значения полей. Это опасно, если класс управляет ресурсами (память, файлы и т. д.).
*/

class GoodString {
private:
    char* data;
    size_t length;

public:
    // Конструктор
    GoodString(const char* str) {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }

    // Деструктор
    ~GoodString() {
        delete[] data;
    }

    // Конструктор копирования
    GoodString(const GoodString& other) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Оператор присваивания копированием
    GoodString& operator=(const GoodString& other) {
        if (this != &other) { // Защита от самоприсваивания
            delete[] data; // Освобождаем старый ресурс
            length = other.length;
            data = new char[length + 1];
            std::strcpy(data, other.data);
        }
        return *this;
    }

    void print() const {
        std::cout << "String: " << data << ", Address: " << (void*)data << std::endl;
    }
};

int main() {
    std::cout << "=== Правило трёх и пяти: демонстрация ===\n\n";

    // Правило трёх: копирование
    std::cout << "1. Копирование (правило трёх):\n";
    GoodString s1("Original");
    s1.print();
    GoodString s2 = s1; // Вызов конструктора копирования
    s2.print();

    return 0;
}

