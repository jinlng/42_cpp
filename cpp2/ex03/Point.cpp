#include "Point.hpp"

// 1. 默认构造函数 Default Constructor（属于 OCF，初始化列表）
Point::Point(void) : _x(0), _y(0) {}

// 2. 参数构造（属于业务，初始化列表）
Point::Point(const float x, const float y) : _x(x), _y(y) {}

// 3. 拷贝构造（属于 OCF，也是初始化列表）
Point::Point(const Point& src) : _x(src._x), _y(src._y) {}

// 4. 拷贝赋值运算符（属于 OCF，但它彻底残疾了）
Point& Point::operator=(const Point& rhs) {
    // 属性是 const 无法被修改，因此这里什么都做不了。
    // 对象的 const 属性在生命周期中不可变，直接返回 *this 符合 OCF 语法即可。
    (void)rhs;
    return *this;
}

// 5. 析构函数 Destructor
Point::~Point(void) {}

Fixed Point::getX(void) const { return this->_x; }
Fixed Point::getY(void) const { return this->_y; }