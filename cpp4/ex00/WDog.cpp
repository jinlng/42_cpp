#include "WDog.hpp"

WDog::WDog()
{
    std::cout << "🐺 Wrong Dog default constructor called" << std::endl;
    _type = "WDog";
}

WDog::WDog(const WDog &other) : WAnimal(other)
{
    std::cout << "🐺 Wrong Dog copy constructor called" << std::endl;
}

WDog &WDog::operator=(const WDog &other)
{
    std::cout << "🐺 Wrong Dog copy assignment operator called" << std::endl;
    if (this != &other)
        WAnimal::operator=(other);
    return (*this);
}

WDog::~WDog()
{
    std::cout << "🐺 Wrong Dog destructor called 🦊" << std::endl;
}

void WDog::makeSound() const
{
    std::cout << "Woof Woof! 🦊" << std::endl;
}