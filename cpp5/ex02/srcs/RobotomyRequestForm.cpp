#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) 
    : AForm("Robotomy Request", 72, 45), _target("DefaultTarget") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) 
    : AForm(src), _target(src._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
        this->_target = rhs._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    // 1. 优先校验权限和签署状态
    this->checkExecution(executor);

    // 2. 执行特定动作
    std::cout << "* BZZZZZZ! BZZZZZZ! DRILLING NOISES *" << std::endl;
    if (std::rand() % 2 == 0) {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy on " << this->_target << " failed!" << std::endl;
    }
}