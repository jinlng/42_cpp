#include "FragTrap.hpp"

// 1. 默认构造函数 Default Constructor
FragTrap::FragTrap(void) : ClapTrap()
{
    this->_name = "Default_Frag";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " default constructed!" << std::endl;
}

// Parameterized constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " parameterized constructed!" << std::endl;
}

// 2. 拷贝构造函数 Copy Constructor
FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
    std::cout << "FragTrap copy constructor called for " << src._name << "!" << std::endl;
    *this = src;
}

// 3. 赋值运算符重载 Copy Assignment Operator Overload
FragTrap& FragTrap::operator=(const FragTrap &rhs) {
    std::cout << "FragTrap copy assignment called for " << rhs._name << "!" << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs); // 调用父类的赋值运算符重载
    }
    return (*this);
}

// 4. 析构函数 Destructor
FragTrap::~FragTrap(void) {
    std::cout << "FragTrap " << this->_name << " destructed!" << std::endl;
}

// FragTrap 专属技能
void FragTrap::highFivesGuys(void) {
    if (this->_hitPoints == 0) {
        std::cout << "FragTrap " << this->_name << " is dead and cannot give high fives!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->_name << " says \"Give me a HIGH FIVE, guys! 🖐️\"" << std::endl;
}
