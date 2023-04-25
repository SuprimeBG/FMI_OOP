#include <iostream>

class Animal {
public:
    Animal(const char* name, const char* type)
        : m_name(name), m_type(type)
    {}
    virtual void talk() = 0;
protected:
    const char* m_name;
    const char* m_type;
};

class Cat : public Animal {
public:
    Cat(const char* name)
        : Animal(name, "cat")
    {}
    void talk() override {
        std::cout << m_name << " says meow!" << std::endl;
    }
};

class Dog : public Animal {
public:
    Dog(const char* name)
        : Animal(name, "dog")
    {}
    void talk() override {
        std::cout << m_name << " says woof!" << std::endl;
    }
};

int main() {
    Animal* animals[2];
    animals[0] = new Cat("Whiskers");
    animals[1] = new Dog("Fido");

    for (int i = 0; i < 2; i++) {
        animals[i]->talk();
        delete animals[i];
    }

    return 0;
}
