#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int					_fixedPointValue;   // 存储定点数的原始整型值
	static const int	_fractionalBits = 8;// 分数部分占用的位数(恒为8)

public:
	// ----- OCF -----
	Fixed(void);						// 1. 默认构造函数 Default Constructor
	Fixed(const Fixed& src);			// 2. 拷贝构造函数 Copy Constructor
	Fixed& operator=(const Fixed& rhs);	// 3. 拷贝赋值运算符重载 Copy Assignment Operator Overload
	~Fixed(void);						// 4. 析构函数 Destructor

	// 原始位操作
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	// 参考构造函数
	Fixed(const int intVal);
	Fixed(const float floatVal);
	
	// 转换成员函数
	float	toFloat(void) const;
	int		toInt(void) const;

	// --- 1. 六个比较运算符重载 ---
    bool    operator>(const Fixed& rhs) const;
    bool    operator<(const Fixed& rhs) const;
    bool    operator>=(const Fixed& rhs) const;
    bool    operator<=(const Fixed& rhs) const;
    bool    operator==(const Fixed& rhs) const;
    bool    operator!=(const Fixed& rhs) const;

    // --- 2. 四个算术运算符重载 ---
    Fixed   operator+(const Fixed& rhs) const;
    Fixed   operator-(const Fixed& rhs) const;
    Fixed   operator*(const Fixed& rhs) const;
    Fixed   operator/(const Fixed& rhs) const;

    // --- 3. 四个自增/自减运算符重载 ---
    Fixed&  operator++(void);       // 前置 ++
    Fixed   operator++(int);        // 后置 ++
    Fixed&  operator--(void);       // 前置 --
    Fixed   operator--(int);        // 后置 --

    // --- 4. 四个重载的静态最大/最小值函数 ---
    static Fixed&          min(Fixed& a, Fixed& b);
    static const Fixed&    min(const Fixed& a, const Fixed& b);
    static Fixed&          max(Fixed& a, Fixed& b);
    static const Fixed&    max(const Fixed& a, const Fixed& b);
};

// 全局函数
std::ostream& operator<<(std::ostream& o, const Fixed& rhs);

#endif