#include "Brain.hpp"

Brain::Brain() {
    std::cout << "🧠 Brain default constructed." << std::endl;
}

Brain::Brain(const Brain &other) {
    std::cout << "🧠 Brain copy constructor called." << std::endl;
    *this = other;
}

Brain &Brain::operator=(const Brain &other) {
    std::cout << "🧠 Brain copy assignment operator called." << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            _ideas[i] = other._ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "💀 Brain destructor called. " << std::endl;
}

const std::string &Brain::getIdea(int index) const {
    if (index < 0 || index >= 100) {
        throw std::out_of_range("Index out of range");
    }
    return _ideas[index];
}

void Brain::setIdea(int index, const std::string &idea) {
    if (index < 0 || index >= 100) {
        throw std::out_of_range("Index out of range");
    }
    _ideas[index] = idea;
}
