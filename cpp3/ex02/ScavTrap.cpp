#include "ScavTrap.hpp"

// 1. 默认构造函数 Default Constructor 初始化
ScavTrap::ScavTrap(void) : ClapTrap()
{
    this->_name = "Default_Scav";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " default constructed!" << std::endl;
}

// 带参构造函数
ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " constructed!" << std::endl;
}

// 2. 拷贝构造函数 Copy Constructor
ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
    std::cout << "ScavTrap copy constructor called for " << src._name << "!" << std::endl;
    *this = src;
}

// 3. 赋值运算符重载 Copy Assignment Operator Overload
ScavTrap& ScavTrap::operator=(const ScavTrap &rhs) {
    std::cout << "ScavTrap copy assignment operator called!" << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs); // 调用父类的赋值运算符重载
    }
    return (*this);
}

// 4. 析构函数 Destructor
ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap " << this->_name << " destructed!" << std::endl;
}

// 攻击函数
void ScavTrap::attack(const std::string &target) {
    if (this->_hitPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " invalid attack, DEAD !" << std::endl;
            return;
    }
    if (this->_energyPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " invalid attack, out of energy !" << std::endl;
            return;
    }
    this->_energyPoints--;
    std::cout << "ScavTrap " << this->_name << " ATTACKS " << target << ", causing " << this->_attackDamage << " points of damage !" << std::endl;
}

// ScavTrap 专属技能
void ScavTrap::guardGate(void) {
    if (this->_hitPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " is dead and cannot enter Gatekeeper mode!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}