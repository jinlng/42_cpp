#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    Fixed const _x;
    Fixed const _y;

public:
    // --- OCF 四件套 ---
    Point(void);
    Point(const Point& src);
    Point& operator=(const Point& rhs); 
    ~Point(void);

    // 浮点坐标构造函数
    Point(const float x, const float y);

    // 普通成员函数
    Fixed getX(void) const;
    Fixed getY(void) const;
};

// BSP 判定函数声明
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif