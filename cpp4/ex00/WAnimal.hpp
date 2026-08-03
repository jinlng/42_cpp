#ifndef WANIMAL_HPP
# define WANIMAL_HPP

# include <iostream>
# include <string>

class WAnimal {
    protected:
        std::string _type;

    public:
        WAnimal();                               // 1. 默认构造函数 Default Constructor
        WAnimal(const WAnimal& other);            // 2. 拷贝构造函数 Copy Constructor
        WAnimal &operator=(const WAnimal &other); // 3. 拷贝赋值运算符重载 Copy Assignment Operator Overload
        ~WAnimal();                      // 4. 析构函数 Destructor
        
         // --- 核心动作函数 ---
        void makeSound() const;
        const std::string &getType() const;
};

#endif