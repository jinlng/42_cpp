#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; // Forward declaration

class Form {
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _gradeToSign;
    const int           _gradeToExecute;

public:
    // --- Orthodox Canonical Form ---
    Form(void);
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form(void);

    // --- Getters ---
    const std::string& getName(void) const;
    bool isSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;

    // --- Member Function : Signing the form ---
    void beSigned(const Bureaucrat& b);

    // --- Exception Classes ---
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

// --- Overload the insertion operator for Form ---
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif