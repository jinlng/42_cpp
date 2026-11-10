#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    // OCF: 构造、拷贝、赋值、析构
    Intern(void);
    Intern(const Intern& src);
    Intern& operator=(const Intern& rhs);
    ~Intern(void);

    // 核心工厂方法：根据表单名称和目标，在堆上创建并返回对应表单指针
    AForm* makeForm(const std::string& formName, const std::string& target);

    // --- Exception Class ---
    // 可选的自定义异常类（如果你的实现中选择抛出异常而不是返回 NULL）
    class InvalidFormException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

#endif