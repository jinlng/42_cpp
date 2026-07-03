#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string _name;

public:
    // 1. 默认构造函数
    Zombie(void);
    // 2. 拷贝构造函数
    Zombie(const Zombie& src);
    // 3. 赋值运算符重载
    Zombie& operator=(const Zombie& rhs);
    // 4. 析构函数
    ~Zombie(void);

    // 额外功能性函数
    Zombie(std::string name);
    void setName(std::string name); // 新增：Setter，用来后续初始化名字
    void announce(void) const;
};

// 全局函数声明
Zombie* zombieHorde(int N, std::string name);

#endif