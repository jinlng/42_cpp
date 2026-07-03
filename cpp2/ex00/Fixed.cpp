#include "Fixed.hpp"

// 1. 默认构造函数 Default Constructor
// initializes the fixed-point number value to 0
Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// 2. 拷贝构造函数 Copy Constructor
Fixed::Fixed(const Fixed& src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

// 3. 赋值运算符重载 Copy Assignment Operator Overload
Fixed& Fixed::operator=(const Fixed& rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->_fixedPointValue = rhs.getRawBits();
    }
    return *this;
}

// 4. 析构函数 Destructor
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

// 获取原始位值 returns the raw value of the fixed-point value:
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

// 设置原始位值 sets the raw value of the fixed-point number:
void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}