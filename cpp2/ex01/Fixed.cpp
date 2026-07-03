#include "Fixed.hpp"

// 1. 默认构造函数 Default Constructor
//      初始化为0: initializes the fixed-point number value to 0
Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

//      整数构造函数: 整数（int）转定点数
Fixed::Fixed(const int intVal) {
    std::cout << "Int constructor called" << std::endl;
    // 整数左移8位存入底层(腾出低8位给潜在小数)
    this->_fixedPointValue = intVal << _fractionalBits;
}

//      浮点数构造函数: 浮点数（float）转定点数
Fixed::Fixed(const float floatVal) {
    std::cout << "Float constructor called" << std::endl;
    // 乘以 256.0f 并四舍五入(强转为整型存起来)
    // float乘int时会变成float                    1向左移动8位=256
    this->_fixedPointValue = roundf(floatVal * (1 << _fractionalBits));
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
    return this->_fixedPointValue;
}

// 设置原始位值 sets the raw value of the fixed-point number:
void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

//定点数转浮点数 fixed -> float
float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

// 定点数转整数 fixed -> int
int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;
}

// 全局输出流运算符重载实现
// 当执行 std::cout << a 时，实际上是在这里调用 a.toFloat() 打印浮点形式
std::ostream& operator<<(std::ostream& o, const Fixed& rhs) {
    o << rhs.toFloat();
    return o;
}