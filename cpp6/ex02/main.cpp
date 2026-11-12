#include <iostream>     // 用于 std::cout
#include <cstdlib>      // 提供 std::rand()
#include <ctime>        // 提供 std::time
#include "Base.hpp"
#include "a.hpp"
#include "b.hpp"
#include "c.hpp"

// Randomly instantiate A, B, or C
Base* generate(void) {
    // std::rand() % 3 会生成 0、1 或 2 三种随机结果
    int random = std::rand() % 3;
    if (random == 0) {
        return new A();
    } else if (random == 1) {
        return new B();
    } else {
        return new C();
    }
}

// Identify via Pointer
// dynamic_cast returns NULL if the cast fails
void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
}

// Identify via Reference
// dynamic_cast throws std::bad_cast if the cast fails on a reference
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}
}

int main() {
    // 整个程序生命周期只初始化一次随机种子
    std::srand(std::time(NULL));

    for (int i = 0; i < 4; i++) {
        std::cout << "Test " << i + 1 << ": ";
        Base* obj = generate();
        
        std::cout << "Identified (Pointer):   ";
        identify(obj);
        
        std::cout << "Identified (Reference): ";
        identify(*obj);

        delete obj;
        std::cout << "------------------------" << std::endl;
    }

    return 0;
}