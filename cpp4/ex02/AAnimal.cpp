#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
    std::cout << "🅰️Animal default constructed. 🏞️" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) {
    std::cout << "🅰️Animal copy constructor called. " << std::endl;
    *this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    std::cout << "🅰️Animal copy assignment operator called" << std::endl;
    if (this != &other)
        _type = other._type;
    return (*this);
}

AAnimal::~AAnimal() {
    std::cout << "🅰️Animal destructor called 💀" << std::endl;
}

const std::string &AAnimal::getType() const {
    return (_type);
}