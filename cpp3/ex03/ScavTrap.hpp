#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        // ----- OCF -----
        ScavTrap(void);                 // 1. 默认构造函数 Default Constructor
        ScavTrap(std::string name);     //    命名构造函数
        ScavTrap(const ScavTrap &src);// 2. 拷贝构造函数 Copy Constructor
        ScavTrap& operator=(const ScavTrap &rhs);// 3. 拷贝赋值运算符重载 Copy Assignment Operator Overload
        ~ScavTrap(void);                // 4. 析构函数 Destructor
        
        // --- 核心动作函数 ---
        void attack(const std::string &target);
        void guardGate(void);
};

#endif