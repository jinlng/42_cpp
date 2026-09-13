#include "Dog.hpp"

Dog::Dog() : AAnimal(), _brain(new Brain()) {
    std::cout << "🐶 Dog default constructor called" << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog &other) : AAnimal(other), _brain(new Brain(*other._brain))
{
    std::cout << "🐶 Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "🐶 Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        *_brain = *other._brain;
    }
    return (*this);
}

Dog::~Dog() {
    delete _brain;
    std::cout << "💥 Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "🐕 Woof Woof!" << std::endl;
}

Brain *Dog::getBrain() const {
    std::cout << "🐶 Dog getBrain() called 🧠" << std::endl;
    return _brain;
}