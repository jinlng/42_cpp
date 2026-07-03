#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    // 防御性编程：如果输入的数量不合法，直接返回指针空壳
    if (N <= 0) {
        return NULL;
    }

    // 1. 在堆上单次分配（Single Allocation）容纳 N 个僵尸的内存空间
    Zombie* horde = new Zombie[N];

    // 2. 遍历这群僵尸，逐个用 Setter 给它们冠名
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }

    // 3. 返回指向这一排僵尸中“第一个僵尸”的指针
    return horde;
}
