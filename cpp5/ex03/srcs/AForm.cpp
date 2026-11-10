#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src)
    : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

AForm& AForm::operator=(const AForm& rhs) {
    if (this != &rhs) {
        this->_isSigned = rhs._isSigned;
    }
    return *this;
}

AForm::~AForm(void) {}

std::string AForm::getName(void) const { return this->_name; }
bool AForm::getIsSigned(void) const { return this->_isSigned; }
int AForm::getGradeToSign(void) const { return this->_gradeToSign; }
int AForm::getGradeToExecute(void) const { return this->_gradeToExecute; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}

void AForm::checkExecution(const Bureaucrat& executor) const {
    if (!this->_isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Form Exception: Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form Exception: Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form Exception: Form is not signed yet!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form: " << form.getName() 
       << " | Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << " | Grade required to sign: " << form.getGradeToSign()
       << " | Grade required to exec: " << form.getGradeToExecute();
    return os;
}