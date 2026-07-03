#include "Point.hpp"

// 计算点 p1 相对于有向线段 p2->p3 的相对位置
static Fixed sign(Point const p1, Point const p2, Point const p3) {
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed d1 = sign(point, a, b);
    Fixed d2 = sign(point, b, c);
    Fixed d3 = sign(point, c, a);

    // 检查是否有严格的正数或负数
    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    // 如果任何一个面积基准为 0，说明点在边界或顶点上
    if (d1 == 0 || d2 == 0 || d3 == 0) {
        return false;
    }

    // 如果不同时包含正符号和负符号，说明绝对同号，点在内部
    return !(has_neg && has_pos);
}