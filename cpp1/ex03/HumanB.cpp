#include "HumanB.hpp"

HumanB::HumanB() : _name("Default_B"), _weapon(NULL) {}

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {} // 初始赤手空拳

HumanB::HumanB(const HumanB& src) { *this = src; }

HumanB& HumanB::operator=(const HumanB& rhs) {
    if (this != &rhs) {
        this->_name = rhs._name;
        this->_weapon = rhs._weapon; // 指针可以直接复制换绑！
    }
    return *this;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon; // 取引用的地址存入指针
}

void HumanB::attack() const {
    if (this->_weapon != NULL) {
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    } else {
        std::cout << this->_name << " attacks with their bare hands (unarmed)!" << std::endl;
    }
}