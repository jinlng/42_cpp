#include "WDog.hpp"

WDog::WDog()
{
    std::cout << "WDog default constructor called" << std::endl;
    _type = "WDog";
}

WDog::WDog(const WDog &other) : WAnimal(other)
{
    std::cout << "WDog copy constructor called" << std::endl;
}

WDog &WDog::operator=(const WDog &other)
{
    std::cout << "WDog copy assignment operator called" << std::endl;
    if (this != &other)
        WAnimal::operator=(other);
    return (*this);
}

WDog::~WDog()
{
    std::cout << "WDog destructor called" << std::endl;
}

void WDog::makeSound() const
{
    std::cout << "Woof Woof!" << std::endl;
}