#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm; // Forward declaration

class Bureaucrat {
private:
    const std::string   _name;
    int                 _grade;

public:
    // --- Orthodox Canonical Form ---
    Bureaucrat(void);
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat(void);

    // --- Getters ---
    const std::string& getName() const;
    int getGrade() const;

    // --- Member Function : 等级调整 ---
    void incrementGrade();
    void decrementGrade();

    // --- NEW Member Function : Signing a form ---
    void signForm(AForm& form);
    
    // --- NEW NEW Member Function : Execute a form ---
    void executeForm(AForm const & form);

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

// --- Overload the insertion operator for Bureaucrat ---
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif