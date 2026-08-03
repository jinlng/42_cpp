#include "WCat.hpp"

WCat::WCat()
{
    std::cout << "WCat default constructor called" << std::endl;
    _type = "WCat";
}

WCat::WCat(const WCat &other) : WAnimal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

WCat &WCat::operator=(const WCat &other)
{
    std::cout << "WCat copy assignment operator called" << std::endl;
    if (this != &other)
        WAnimal::operator=(other);
    return (*this);
}

WCat::~WCat()
{
    std::cout << "WCat destructor called" << std::endl;
}

void WCat::makeSound() const
{
    std::cout << "Meow Meow!" << std::endl;
}