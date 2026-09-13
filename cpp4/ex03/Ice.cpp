#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << "❄️ Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
    std::cout << "❄️ Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
    std::cout << "❄️ Ice copy assignment operator called" << std::endl;
    if (this != &other) {
        AMateria::operator=(other);
    }
    return (*this);
}

Ice::~Ice() {
    std::cout << "💀 Ice destructor called" << std::endl;
}

// Implement the use function to print a message when the materia is used
AMateria* Ice::clone() const {
    std::cout << "❄️ Ice clone() called" << std::endl;
    return (new Ice(*this));
}

void Ice::use(ICharacter &target) {
    std::cout  << "* shoots an ice bolt at "
                << target.getName() 
                << " *" << std::endl;
}