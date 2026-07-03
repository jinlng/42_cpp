#include "Zombie.hpp"

// Heap Allocation
Zombie* newZombie(std::string name) {
    // 使用 new 分配内存，对象在堆上存活，函数结束后不会自动销毁
    return new Zombie(name);
}