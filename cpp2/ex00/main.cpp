#include "Fixed.hpp"

int main(void)
{
    // 触发默认构造，此时 a._fixedPointValue = 0;
    Fixed a;

    // 触发拷贝构造
    Fixed b(a);

    // 再次触发默认构造
    Fixed c;

    // 触发拷贝赋值运算符
    c = b;

    // 显式调用 abc 的 getRawBits
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}