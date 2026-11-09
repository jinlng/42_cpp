#include "Bureaucrat.hpp"
#include "Form.hpp"

// 默认构造函数
// 默认状态为未签署 (_isSigned = false)，签署和执行等级均为最低的 150
Form::Form(void) : _name("Default Form 📋"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

// 带参数的构造函数：根据传入的名称和权限门槛初始化表单
// 新创建的表单初始状态始终为未签署 (_isSigned 统一内部设为 false，无需由外部传入)
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    // 校验等级边界（合法范围为 1 到 150），越界则直接抛出异常阻止对象构造
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        // _name, _gradeToSign, and _gradeToExecute are const, so we cannot assign to them
        // this->_name = other._name; // This line would cause a compilation error
        // this->_gradeToSign = other._gradeToSign; // This line would cause a compilation error
        // this->_gradeToExecute = other._gradeToExecute; // This line would cause a compilation error
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form(void) {}

// --- Getters ---
const std::string& Form::getName(void) const { return _name; }
bool Form::isSigned(void) const { return _isSigned; }
int Form::getGradeToSign(void) const { return _gradeToSign; }
int Form::getGradeToExecute(void) const { return _gradeToExecute; }

// --- Member Function : Signing the form ---
void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// --- Exception Classes ---
const char* Form::GradeTooHighException::what() const throw() {
    return "Form Exception: Grade is too high! Who are you trying to impress, maggots?";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form Exception: Grade is too low to sign this form, maggots!";
}

// --- Overload the insertion operator for Form ---
std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form Name: " << f.getName()
       << ", Signed: " << (f.isSigned() ? "Yes" : "No")
       << ", Grade to Sign: "<< f.getGradeToSign() 
       << ", Grade to Execute: " << f.getGradeToExecute() << ".";
    return os;
}