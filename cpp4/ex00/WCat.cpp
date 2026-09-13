#include "WCat.hpp"

WCat::WCat()
{
    std::cout << "🦁 Wrong Cat default constructor called" << std::endl;
    _type = "WCat";
}

WCat::WCat(const WCat &other) : WAnimal(other)
{
    std::cout << "🦁 Wrong Cat copy constructor called" << std::endl;
}

WCat &WCat::operator=(const WCat &other)
{
    std::cout << "🦁 Wrong Cat copy assignment operator called" << std::endl;
    if (this != &other)
        WAnimal::operator=(other);
    return (*this);
}

WCat::~WCat()
{
    std::cout << "🦁 Wrong Cat destructor called 🦦" << std::endl;
}

void WCat::makeSound() const
{
    std::cout << "Meow Meow! 🐆" << std::endl;
}