#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
private:
    // 四个私有的抱怨函数
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    // --- OCF 四件套 开始 ---
    Harl(void);                             // 1. 默认构造
    Harl(const Harl& src);                  // 2. 拷贝构造
    Harl& operator=(const Harl& rhs);       // 3. 拷贝赋值
    ~Harl(void);                            // 4. 析构函数
    // --- OCF 四件套 结束 ---

    // 唯一的公开大门
    void complain(std::string level);
};

#endif