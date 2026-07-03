#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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

	// 成员功能函数
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif