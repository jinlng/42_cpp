#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
    protected:
        std::string _type;

    public:
        Animal();                               // 1. 默认构造函数 Default Constructor
        Animal(const Animal& other);            // 2. 拷贝构造函数 Copy Constructor
        Animal &operator=(const Animal &other); // 3. 拷贝赋值运算符重载 Copy Assignment Operator Overload
        virtual ~Animal();                      // 4. 析构函数 Destructor
        
         // --- 核心动作函数 ---
        virtual void makeSound() const;
        const std::string &getType() const;
};

#endif