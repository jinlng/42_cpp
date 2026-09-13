#include "WAnimal.hpp"


WAnimal::WAnimal() : _type("WAnimal") {
    std::cout << "🪼  Wrong Animal default constructed. 🚧 " << std::endl;
}

// 2. 拷贝构造函数 Copy Constructor
WAnimal::WAnimal(const WAnimal &other) {
    std::cout << "🪼  Wrong Animal copy constructor called. " << std::endl;
    *this = other;
}

WAnimal &WAnimal::operator=(const WAnimal &other)
{
    std::cout << "🪼  Wrong Animal copy assignment operator called" << std::endl;
    if (this != &other)
        _type = other._type;
    return (*this);
}

WAnimal::~WAnimal()
{
    std::cout << "🪼  Wrong Animal destructor called" << std::endl;
}

const std::string &WAnimal::getType() const
{
    return (_type);
}

void WAnimal::makeSound() const
{
    std::cout << "* (Wrong Animal sound) *" << std::endl;
}