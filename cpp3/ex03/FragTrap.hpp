#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include  "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        // ----- OCF -----
        FragTrap(void);                 // 1. 默认构造函数 Default Constructor
        FragTrap(std::string name);     //    命名构造函数
        FragTrap(const FragTrap &src);// 2. 拷贝构造函数 Copy Constructor
        FragTrap& operator=(const FragTrap &rhs);// 3. 拷贝赋值运算符重载 Copy Assignment Operator Overload
        ~FragTrap(void);                // 4. 析构函数 Destructor
        
        // --- 核心动作函数 ---
        void highFivesGuys(void);
};

#endif