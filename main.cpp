#include <iostream>

struct Person
{
    std::string name;
    std::string surname;
    int age;

    void sayYourName()
    {
        std::cout << "Name is: " << name << ", " << "Surname is: " << surname << std::endl;
    }
};

class SimplePerson
{
public:
    std::string name;
    std::string surname;
    int age;

    void sayYourName()
    {
        std::cout << "Name is: " << name << ", " << "Surname is: " << surname << std::endl;
    }

    SimplePerson(std::string _name, std::string _surname, int _age):
    name{_name + "52"}, surname{_surname}, age{age}
    {
        std::cout << "Constructor" << std::endl;
    }
    ~SimplePerson()
    {
        std::cout << "Destructor" << std::endl;
    }
};



int main()
{
    std::cout << "start" << std::endl;

    {
        SimplePerson p{"Maxim", "Osipov", 18};
        std::cout << "initialized" << std::endl;
        p.sayYourName();
        std::cout << "after say" << std::endl;
    }

    std::cout << "end" << std::endl;
    return 0;
}