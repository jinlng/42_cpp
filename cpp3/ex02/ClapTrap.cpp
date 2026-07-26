#include "ClapTrap.hpp"

// 1. 默认构造函数 Default Constructor 初始化
ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10),
                           _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " default constructed!" << std::endl;
}

// 带参构造函数
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
                                       _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
}

// 2. 拷贝构造函数 Copy Constructor
ClapTrap::ClapTrap(const ClapTrap &src) {
    std::cout << "ClapTrap copy constructor called for " << src._name << "!" << std::endl;
    *this = src;
}

// 3. 赋值运算符重载 Copy Assignment Operator Overload
ClapTrap& ClapTrap::operator=(const ClapTrap &rhs) {
    std::cout << "ClapTrap copy assignment operator called!" << std::endl;
    if (this != &rhs) {
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return (*this);
}

// 4. 析构函数 Destructor
ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap " << _name << " destructed!" << std::endl;
}

// 攻击函数
void ClapTrap::attack(const std::string &target) {
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " cannot attack, DEAD !" << std::endl;
            return;
    }
    if (this->_energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " cannot attack, out of energy !" << std::endl;
            return;
    }
    this->_energyPoints--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage !" << std::endl;
}

// 受到伤害函数
void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " is already dead, stop hitting it !" << std::endl;
            return;
    }
    // 防溢出判断：如果受到的伤害大于剩余血量，直接扣到 0
    if ((int)amount >= this->_hitPoints) {
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage and dies!" << std::endl;
    }
    else {
        this->_hitPoints -= amount;
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage! Remaining HP: " << this->_hitPoints << std::endl;
    }
}

// 修复函数
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " cannot repair itself, because it's dead!" << std::endl; return;
    }
    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " cannot repair itself, out of energy !" << std::endl;
            return;
    }
    this->_energyPoints--;
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << this->_name << " repairs itself, getting " << amount << " hit points back !Current HP : " << this->_hitPoints << std::endl;
}
