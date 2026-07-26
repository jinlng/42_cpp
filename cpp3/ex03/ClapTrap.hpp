#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    protected:
        std::string	_name;
        int			_hitPoints;
        int			_energyPoints;
        int			_attackDamage;

    public:
        // ----- OCF -----
        ClapTrap(void);                 // 1. 默认构造函数 Default Constructor
        ClapTrap(std::string name);     //    命名构造函数
        ClapTrap(const ClapTrap &other);// 2. 拷贝构造函数 Copy Constructor
        ClapTrap& operator=(const ClapTrap &other);// 3. 拷贝赋值运算符重载 Copy Assignment Operator Overload
        ~ClapTrap(void);                // 4. 析构函数 Destructor
        
        // --- 核心动作函数 ---
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif