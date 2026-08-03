#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << "Animal default constructed. 🚧 " << std::endl;
}

// 2. 拷贝构造函数 Copy Constructor
Animal::Animal(const Animal &other) {
    std::cout << "Animal copy constructor called. " << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
        _type = other._type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

const std::string &Animal::getType() const
{
    return (_type);
}

void Animal::makeSound() const
{
    std::cout << "* Animal sound *" << std::endl;
}