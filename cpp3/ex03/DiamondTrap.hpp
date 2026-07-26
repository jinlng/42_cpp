#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;

    public:
        // ----- OCF -----
        DiamondTrap(void);                 // 1. 默认构造函数 Default Constructor
        DiamondTrap(std::string name);     //    命名构造函数
        DiamondTrap(const DiamondTrap &src);// 2. 拷贝构造函数 Copy Constructor
        DiamondTrap& operator=(const DiamondTrap &rhs);// 3. 拷贝赋值运算符重载 Copy Assignment Operator Overload
        ~DiamondTrap(void);                // 4. 析构函数 Destructor
        
        // --- 核心动作函数 ---
        using ScavTrap::attack; // Explicitly use ScavTrap's attack method
        void whoAmI(void);
};

#endif