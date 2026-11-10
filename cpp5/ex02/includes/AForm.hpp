#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; // Forward declaration

class AForm {
private:
    const std::string _name;
    bool              _isSigned;
    const int         _gradeToSign;
    const int         _gradeToExecute;

public:
    AForm(void);
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& src);
    AForm& operator=(const AForm& rhs);
    virtual ~AForm(void);

    // Getters
    std::string getName(void) const;
    bool        getIsSigned(void) const;
    int         getGradeToSign(void) const;
    int         getGradeToExecute(void) const;

    // Actions
    void         beSigned(const Bureaucrat& b);
    virtual void execute(const Bureaucrat& executor) const = 0; // 纯虚函数

    // 基础检查工具函数（供派生类在 execute 中调用）
    void checkExecution(const Bureaucrat& executor) const;

    // Exceptions
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif