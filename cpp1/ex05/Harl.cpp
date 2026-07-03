#include "Harl.hpp"

Harl::Harl(void) {}

Harl::Harl(const Harl& src) { *this = src; }

Harl& Harl::operator=(const Harl& rhs) {
    (void)rhs; // 因为 Harl 内部没有属性变量，这里直接忽略参数以防 compiler warning
    return *this;
}

Harl::~Harl(void) {}

void Harl::debug(void) {
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level) {
    // 1. 定义类成员函数指针的别名（让代码好看十倍的核心技巧）
    typedef void (Harl::*HarlMemFn)(void);

    // 2. 映射表：字符串数组
    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    // 3. 映射表：对应的成员函数指针数组
    HarlMemFn actions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    // 4. 循环查表，只要匹配成功，立刻调用并返回，绝不用 if-else 嵌套
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*actions[i])(); // ⚡️ 核心语法：通过当前对象的 this 指针调用绑定的函数
            return;
        }
    }

    // 5. 兜底边界处理
    std::cout << "[ Unknown Level ]\n*Harl mutters something incomprehensible*\n" << std::endl;
}