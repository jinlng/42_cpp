#include "Dog.hpp"

// 构造/拷贝构造时：在堆上申请 Brain 内存
Dog::Dog() : Animal(), _brain(new Brain()) {
    std::cout << "🐶 Dog default constructor called" << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*other._brain))
{
    std::cout << "🐶 Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "🐶 Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        // deep copy
        if (this->_brain && other._brain) {
            *this->_brain = *other._brain;
        }
    }
    return (*this);
}

// 析构时：必须显式 delete，释放这块堆内存！
Dog::~Dog() {
    delete _brain; // Dog dynamically owns Brain
    std::cout << "🐶 Dog destructor called 💥" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "🐕 Woof Woof!" << std::endl;
}

Brain *Dog::getBrain() const {
    // std::cout << "🐶 Dog getBrain() called 🧠" << std::endl;
    return _brain;
}