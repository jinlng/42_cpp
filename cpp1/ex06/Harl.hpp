#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    // --- OCF 四件套 开始 ---
    Harl(void);
    Harl(const Harl& src);
    Harl& operator=(const Harl& rhs);
    ~Harl(void);
    // --- OCF 四件套 结束 ---

    // 过滤执行接口
    void complainFilter(std::string level);
};

#endif