#include "Fixed.hpp"

// 1. 默认构造函数 Default Constructor 初始化为 0
Fixed::Fixed(void) : _fixedPointValue(0) {}

// 整数构造函数: 整数（int）转定点数
Fixed::Fixed(const int intVal) : _fixedPointValue(intVal << _fractionalBits) {}

// 浮点数构造函数: 浮点数（float）转定点数
Fixed::Fixed(const float floatVal) : _fixedPointValue(roundf(floatVal * (1 << _fractionalBits))){}

// 2. 拷贝构造函数 Copy Constructor
Fixed::Fixed(const Fixed& src) { *this = src; }

// 3. 赋值运算符重载 Copy Assignment Operator Overload
Fixed& Fixed::operator=(const Fixed& rhs) {
    if (this != &rhs) {
        this->_fixedPointValue = rhs.getRawBits();
    }
    return *this;
}

// 4. 析构函数 Destructor
Fixed::~Fixed(void) {}

// 获取原始位值 returns the raw value of the fixed-point value:
int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

// 设置原始位值 sets the raw value of the fixed-point number:
void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

//定点数转浮点数
float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

// 定点数转整数
int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;
}

// I. 比较运算符 (直接比对底层的整型值，效率最高)
bool Fixed::operator>(const Fixed& rhs) const  { 
    return this->_fixedPointValue >  rhs._fixedPointValue; 
}
bool Fixed::operator<(const Fixed& rhs) const  { 
    return this->_fixedPointValue <  rhs._fixedPointValue;
}
bool Fixed::operator>=(const Fixed& rhs) const {
    return this->_fixedPointValue >= rhs._fixedPointValue;
}
bool Fixed::operator<=(const Fixed& rhs) const {
    return this->_fixedPointValue <= rhs._fixedPointValue;
}
bool Fixed::operator==(const Fixed& rhs) const {
    return this->_fixedPointValue == rhs._fixedPointValue;
}
bool Fixed::operator!=(const Fixed& rhs) const {
    return this->_fixedPointValue != rhs._fixedPointValue;
}

// II. 算术运算符 (转换为 float 运算后，重新塞回构造函数)
Fixed Fixed::operator+(const Fixed& rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}
Fixed Fixed::operator-(const Fixed& rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}
Fixed Fixed::operator*(const Fixed& rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}
Fixed Fixed::operator/(const Fixed& rhs) const {
    return Fixed(this->toFloat() / rhs.toFloat());
}

// III. 自增/自减运算符 (针对最小精度1运行: 1/256)
// 前置++(++a): 改变自己，返回自己的引用 Pre-increment 
Fixed& Fixed::operator++(void) {
    this->_fixedPointValue++;
    return *this;
}

// 后置 ++ (a++): 复制旧的，改变自己，返回旧的副本 Post-increment
Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->_fixedPointValue++;
    return tmp;
}

// 前置 -- (--a): 改变自己，返回自己的引用 Pre-decrement 
Fixed& Fixed::operator--(void) {
    this->_fixedPointValue--;
    return *this;
}

// 后置 -- (a--): 复制旧的，改变自己，返回旧的副本 Post-decrement 
Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->_fixedPointValue--;
    return tmp;
}

// IV. 静态最大/最小值成员函数
// const和非const 的重载版本
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// 全局输出流运算符重载实现
std::ostream& operator<<(std::ostream& o, const Fixed& rhs) {
    o << rhs.toFloat();
    return o;
}