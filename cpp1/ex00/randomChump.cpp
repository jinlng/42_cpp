#include "Zombie.hpp"

// Stack Allocation
void randomChump(std::string name) {
    // 在栈上分配，不需要 new，不需要指针
    Zombie zombie(name);
    zombie.announce();
    // 函数结束时，zombie 自动死亡，触发析构函数
}