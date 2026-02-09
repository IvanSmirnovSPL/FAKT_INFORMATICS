#include <iostream>

class Human
{
public:
    Human(std::string _name, std::string _surname, int _age):
    name{_name}, surname{_surname}, age{age}
    {
        std::cout << "Constructor (Human) " << name << std::endl;
    }
    ~Human()
    {
        std::cout << "Destructor (Human) " << name << std::endl;
    }
    std::string name;
    std::string surname;
    int age;

    virtual void sayHi() { std::cout << "silence" << std::endl; }

    void sayYourName()
    {
        std::cout << "Name is: " << name << ", " << "Surname is: " << surname << std::endl;
    }
};

class Male: public Human{
public:
    using Human::Human;

    void sayHi() override { std::cout << "Hi, Bro" << std::endl; }
};

class Female: public Human{
public:
    using Human::Human;

    void sayHi() { std::cout << "Hello, dear" << std::endl; }
};

int main()
{
    Male m{"Maxim", "Osipov", 18};
    Female f{"Emilia", "Aleeva", 18};

    int humansNumber = 2;
    Human* humans[humansNumber];
    humans[0] = &m;
    humans[1] = &f;
    for (int i = 0; i < humansNumber; ++i)
    {
        humans[i]->sayHi();
    }


    return 0;
}