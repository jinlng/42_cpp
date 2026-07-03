#include "HumanA.hpp"

// 必须使用初始化列表（Initialization List）来初始化引用属性！
HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

// 拷贝构造：由于对方已经有绑定的武器了，我们通过初始化列表绑定过去
HumanA::HumanA(const HumanA& src) : _name(src._name), _weapon(src._weapon) {}

// 核心考点：赋值运算符面对“引用属性”时的妥协
HumanA& HumanA::operator=(const HumanA& rhs) {
    if (this != &rhs) {
        this->_name = rhs._name;
        // ⚠️ 注意：这里无法写 this->_weapon = rhs._weapon！
        // 如果写了，改变的是当前武器的值，而不是改变引用的绑定！
    }
    return *this;
}

HumanA::~HumanA() {}

void HumanA::attack() const {
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}