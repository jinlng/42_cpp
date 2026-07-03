#include "Harl.hpp"

Harl::Harl(void) {}

Harl::Harl(const Harl& src) { *this = src; }

Harl& Harl::operator=(const Harl& rhs) {
    (void)rhs;
    return *this;
}

Harl::~Harl(void) {}

void Harl::debug(void) {
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n" << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complainFilter(std::string level) {
    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    int index = -1;

    // 1. 寻找匹配的级别索引
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            index = i;
            break;
        }
    }

    // 2. 核心：利用 switch 的 Fall-through（穿透）特性
    // ⚠️ 注意：每一层 case 故意不加 break，让代码自动向下执行更高级别
    switch (index) {
        case 0:
            this->debug();
            // FALLTHROUGH
        case 1:
            this->info();
            // FALLTHROUGH
        case 2:
            this->warning();
            // FALLTHROUGH
        case 3:
            this->error();
            break; // 最后一层加上 break 结束
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}