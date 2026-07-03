#include "Zombie.hpp"

// Default Constructor 构造函数：出生时赋予名字
Zombie::Zombie(void) : _name("Default_Zombie") {
    std::cout << "[OCF] Default Zombie created." << std::endl;
}

// Copy Constructor 拷贝构造（用另一个僵尸克隆出一个新僵尸）
Zombie::Zombie(const Zombie& src) {
    std::cout << "Zombie: Copy constructor called." << std::endl;
    *this = src; // 直接复用下面写好的赋值运算符逻辑
}

// Copy Assignment Operator Overload 赋值运算符重载
// （把右边僵尸的属性强加给左边的僵尸）
Zombie& Zombie::operator=(const Zombie& rhs) {
    std::cout << "Zombie: Copy assignment operator called." << std::endl;
    if (this != &rhs) { // 防止自我赋值 (z1 = z1)
        this->_name = rhs._name; // 复制属性
    }
    return *this; // 返回自身引用，支持链式赋值 (z1 = z2 = z3)
}

// Destructor 析构函数：死亡时的调试信息
Zombie::~Zombie(void) {
    std::cout << "[Destructor] " << this->_name << " has been destroyed." << std::endl;
}

// ──── 其它普通成员函数 ────
Zombie::Zombie(std::string name) : _name(name) {
    std::cout << "[Constructor] Zombie " << this->_name << " is born." << std::endl;
}

// 叫声
void Zombie::announce(void) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}