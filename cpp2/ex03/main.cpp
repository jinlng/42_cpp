#include "Point.hpp"

void testPoint(Point const a, Point const b, Point const c, Point const p, std::string name) {
    std::cout << "Point " << name << " (" << p.getX() << ", " << p.getY() << ") is ";
    if (bsp(a, b, c, p))
        std::cout << "\033[32mINSIDE\033[0m" << std::endl;
    else
        std::cout << "\033[31mOUTSIDE\033[0m" << std::endl;
}

int main(void) {
    // 建立一个直角三角形：A(0,0), B(4,0), C(0,4)
    Point const a(0, 0);
    Point const b(4, 0);
    Point const c(0, 4);

    std::cout << "=== BSP Geometry Testing ===" << std::endl;
    
    testPoint(a, b, c, Point(1, 1), "P1 (Strictly Inside)");
    testPoint(a, b, c, Point(3, 3), "P2 (Strictly Outside)");
    testPoint(a, b, c, Point(0, 0), "P3 (On Vertex A)");
    testPoint(a, b, c, Point(2, 0), "P4 (On Edge AB)");
    testPoint(a, b, c, Point(2, 2), "P5 (On Hypotenuse BC)");
    testPoint(a, b, c, Point(0.1f, 0.1f), "P6 (Near Vertex Inside)");

    return 0;
}