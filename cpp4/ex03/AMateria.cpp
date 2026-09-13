#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : _type(type) {
    std::cout << "🧪 AMateria constructor called for type: " << _type << std::endl;
}

AMateria::AMateria() : _type("unknown") {
    std::cout << "🧪 AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
    std::cout << "🧪 AMateria copy constructor called for type: " << _type << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
    std::cout << "🧪 AMateria copy assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return (*this);
}

AMateria::~AMateria() {
    std::cout << "💀 AMateria destructor called for type: " << _type << std::endl;
}

const std::string &AMateria::getType() const {
    return (_type);
}

void AMateria::use(ICharacter& target) {
    std::cout << "🧪 AMateria of type " << _type << " used on " << target.getName() << std::endl;
}
