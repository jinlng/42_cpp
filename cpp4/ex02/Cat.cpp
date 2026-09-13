#include "Cat.hpp"

Cat::Cat() : AAnimal(), _brain(new Brain())
{
    std::cout << "🐱 Cat default constructor called" << std::endl;
    _type = "Cat";
}

Cat::Cat(const Cat &other) : AAnimal(other), _brain(new Brain(*other._brain))
{
    std::cout << "🐱 Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "🐱 Cat copy assignment operator called" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        *_brain = *other._brain;
    }
    return (*this);
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "💥 Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "🐈 Meow Meow!" << std::endl;
}

Brain *Cat::getBrain() const {
    std::cout << "🐱 Cat getBrain() called 🧠" << std::endl;
    return _brain;
}