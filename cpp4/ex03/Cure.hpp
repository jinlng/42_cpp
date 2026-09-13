#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
        Cure();                                   // 1. 默认构造函数 Default Constructor
        Cure(const Cure &other);                  // 2. 拷贝构造函数 Copy Constructor
        Cure &operator=(const Cure &other);       // 3. 拷贝赋值运算符重载 Copy Assignment Operator Overload
        virtual ~Cure();                         // 4. 析构函数 Destructor

        virtual AMateria* clone() const;        // Clone the materia
        virtual void use(ICharacter& target);   // Use the materia on a character
};

#endif