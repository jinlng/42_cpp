#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain())
{
    std::cout << "🐱 Cat default constructor called" << std::endl;
    _type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "🐱 Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "🐱 Cat copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        // deep copy
        if (this->_brain && other._brain) {
            *this->_brain = *other._brain;
        }
    }
    return (*this);
}

Cat::~Cat()
{
    delete _brain; // Cat dynamically owns Brain
    std::cout << "🐱 Cat destructor called 💥" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "🐈 Meow Meow!" << std::endl;
}

Brain *Cat::getBrain() const {
    // std::cout << "🐱 Cat getBrain() called 🧠" << std::endl;
    return _brain;
}
