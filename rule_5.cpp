#include <string>
#include <iostream>

/*
Эволюция правила трёх для C++11 и новее с учётом семантики перемещения (move semantics).

Суть: если определяется один из пяти методов, вероятно, нужно определить все пять:

 - деструктор;

 - конструктор копирования;

 - оператор присваивания копированием;

 - конструктор перемещения;

 - оператор присваивания перемещением.

Преимущества перемещения: вместо копирования «забирает» ресурсы у временного объекта — эффективнее.
*/

class ModernString {
private:
    char* data;
    size_t length;

public:
    // Конструктор
    ModernString(const char* str) {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }

    // Деструктор
    ~ModernString() {
        delete[] data;
    }

    // Конструктор копирования (правило трёх)
    ModernString(const ModernString& other) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Оператор присваивания копированием (правило трёх)
    ModernString& operator=(const ModernString& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            std::strcpy(data, other.data);
        }
        return *this;
    }

    // Конструктор перемещения (правило пяти)
    ModernString(ModernString&& other) noexcept
        : data(other.data), length(other.length) {
        other.data = nullptr;  // «Обнуляем» исходный объект
        other.length = 0;
    }

    // Оператор присваивания перемещением (правило пяти)
    ModernString& operator=(ModernString&& other) noexcept {
        if (this != &other) {
            delete[] data;      // Освобождаем текущий ресурс
            data = other.data; // Забираем ресурс
            length = other.length;
            other.data = nullptr; // «Обнуляем» исходный
            other.length = 0;
        }
        return *this;
    }

    void print() const {
        if (data) {
            std::cout << "String: " << data << ", Address: " << (void*)data;
        } else {
            std::cout << "String: [moved from], Address: nullptr";
        }
        std::cout << std::endl;
    }
};


int main() {
    std::cout << "=== Правило трёх: демонстрация ===\n\n";

    std::cout << "\n2. Перемещение (правило пяти):\n";
    ModernString m1("MoveMe");
    m1.print();
    ModernString m2 = std::move(m1); // Вызов конструктора перемещения
    m2.print();
    m1.print(); // m1 теперь в валидном, но «пустом» состоянии

    return 0;
}

