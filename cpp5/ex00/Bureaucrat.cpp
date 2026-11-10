#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    if (_grade < 1)
        throw GradeTooHighException(); // () 表示调用默认构造函数实例化一个临时对象扔出去
    if (_grade > 150)
        throw GradeTooLowException(); // () 表示调用默认构造函数实例化一个临时对象扔出去
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        // _name is const, so we cannot assign to it
        // this->_name = other._name; // This line would cause a compilation error
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat(void) {}

// --- Getters ---
const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// --- Member Function : 等级调整 ---
void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    ++_grade;
}

// --- Exception Classes ---
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade is too low!";
}

// --- Overload the insertion operator for Bureaucrat ---
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrate grade " << b.getGrade() << ".";
    return os;
}