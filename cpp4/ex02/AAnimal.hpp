#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal {
    protected:
        std::string _type;

    public:
        AAnimal();                               // 1. 默认构造函数 Default Constructor
        AAnimal(const AAnimal& other);            // 2. 拷贝构造函数 Copy Constructor
        AAnimal &operator=(const AAnimal &other); // 3. 拷贝赋值运算符重载 Copy Assignment Operator Overload
        virtual ~AAnimal();                      // 4. 析构函数 Destructor
        
         // --- 核心动作函数 ---
        virtual void makeSound() const = 0; // Pure virtual function
        const std::string &getType() const;
};

#endif