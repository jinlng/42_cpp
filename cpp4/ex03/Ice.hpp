#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
    public:
        Ice();                                   // 1. 默认构造函数 Default Constructor
        Ice(const Ice &other);                  // 2. 拷贝构造函数 Copy Constructor
        Ice &operator=(const Ice &other);       // 3. 拷贝赋值运算符重载 Copy Assignment Operator Overload
        virtual ~Ice();                         // 4. 析构函数 Destructor

        virtual AMateria* clone() const;        // Clone the materia
        virtual void use(ICharacter& target);   // Use the materia on a character
};

#endif