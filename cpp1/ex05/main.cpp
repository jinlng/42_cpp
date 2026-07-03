#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "=== Testing Standard Levels ===" << std::endl;
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");

    std::cout << "=== Testing Invalid Level ===" << std::endl;
    harl.complain("TIP"); // 应该走到兜底的分支，程序不能崩溃

    std::cout << "=== Testing OCF Copy ===" << std::endl;
    Harl harlCopy(harl); // 测试拷贝构造
    harlCopy.complain("WARNING");

    return 0;
}