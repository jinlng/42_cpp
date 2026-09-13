#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria();                               // 1. 默认构造函数 Default Constructor
        AMateria(const std::string &type);       // 2. 带参数的构造函数 Parameterized Constructor
        AMateria(const AMateria& other);          // 3. 拷贝构造函数 Copy Constructor
        AMateria &operator=(const AMateria &other); // 4. 拷贝赋值运算符重载 Copy Assignment Operator Overload
        virtual ~AMateria();                      // 5. 析构函数 Destructor

        const std::string &getType() const;       // Returns the materia type

        virtual AMateria* clone() const = 0;      // Pure virtual function to clone the materia
        virtual void use(ICharacter& target);     // Virtual function to use the materia on a character
};

#endif