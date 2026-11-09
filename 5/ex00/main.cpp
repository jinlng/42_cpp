#include "Bureaucrat.hpp"

int main(void) {
    std::cout << "=== Test 1: Normal Construction & Increment ===" << std::endl;
    try {
        Bureaucrat john("John", 3);
        std::cout << john << std::endl;
        john.incrementGrade(); // Grade -> 2
        std::cout << john << std::endl;
        john.incrementGrade(); // Grade -> 1
        std::cout << john << std::endl;
        john.incrementGrade(); // 应该抛出异常！
    } catch (std::exception& e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    std::cout << "Program continues normally without crashing!" << std::endl;

    std::cout << "\n=== Test 2: Invalid Constructor ===" << std::endl;
    // lowest possible is 150
    try {
        Bureaucrat bad1("BadBob1", 151); // Object construction failed 没有被创建出来
        // 不执行 - 位于throw之后所以是Unreachable Code，这里不会被报错但是最号不要写依赖 bad1 成功创建的代码
        // std::cout << bad1 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }
    // highest possible is 1
    try {
        Bureaucrat bad2("BadBoss", 0); // Object construction failed 没有被创建出来
        // 不执行 - 位于throw之后所以是Unreachable Code，这里不会被报错但是最号不要写依赖 bad2 成功创建的代码
        // std::cout << bad2 << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "Program continues normally without crashing!" << std::endl;

    std::cout << "\n=== Test 3: Decrement Out of Bounds ===" << std::endl;
    try {
        Bureaucrat low("LowGuy", 150);
        std::cout << low << std::endl;
        low.decrementGrade(); // 应该抛出异常！
    } catch (std::exception& e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    std::cout << "Program continues normally without crashing!" << std::endl;
   
    return 0;
}