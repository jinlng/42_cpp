#include "DiamondTrap.hpp"

// 1. 默认构造函数 Default Constructor
DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name"), ScavTrap("Default_Scav"), FragTrap("Default_Frag") {
    this->_name = "Default_Diamond";
    this->_hitPoints = FragTrap::_hitPoints; // 继承自 FragTrap 的生命值
    this->_energyPoints = ScavTrap::_energyPoints; // 继承自 ScavTrap 的能量值
    this->_attackDamage = FragTrap::_attackDamage; // 继承自 FragTrap 的攻击力
    std::cout << "DiamondTrap " << this->_name << " default constructed!" << std::endl;
}

// 带参构造函数
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_Scav"), FragTrap(name + "_Frag") {
    this->_hitPoints = FragTrap::_hitPoints; // 继承自 FragTrap 的生命值
    this->_energyPoints = ScavTrap::_energyPoints; // 继承自 ScavTrap 的能量值
    this->_attackDamage = FragTrap::_attackDamage; // 继承自 FragTrap 的攻击力
    std::cout << "DiamondTrap " << this->_name << " constructed with name: " << name << std::endl;
}

// 2. 拷贝构造函数 Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
    std::cout << "DiamondTrap copy constructor called for "<< src._name << "!" << std::endl;
    *this = src;
}  

// 3. 赋值运算符重载 Copy Assignment Operator Overload
DiamondTrap& DiamondTrap::operator=(const DiamondTrap &rhs) {
    std::cout << "DiamondTrap copy assignment operator called!" << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs); // 调用父类的赋值运算符
        this->_name = rhs._name;
    }  
    return (*this);
}

// 4. 析构函数 Destructor
DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap " << this->_name << " destructed!" << std::endl;
}

// whoAmI 函数
void DiamondTrap::whoAmI(void) {
    std::cout << "DiamondTrap name: " << this->_name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
