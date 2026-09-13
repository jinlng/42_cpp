#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
    public:
        Brain();                    // 1. 默认构造函数 Default Constructor
        Brain(const Brain &other);  // 2. 拷贝构造函数 Copy Constructor
        Brain &operator=(const Brain &other); // 3. 拷贝赋值运算符重载 Copy Assignment Operator Overload
        ~Brain();                   // 4. 析构函数 Destructor

        // --- 核心动作函数 ---
        const std::string &getIdea(int index) const;
        void setIdea(int index, const std::string &idea);

    private:
        std::string _ideas[100];
};

#endif