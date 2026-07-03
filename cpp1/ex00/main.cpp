#include "Zombie.hpp"

int main() {
    std::cout << "--- Testing Stack Allocation (randomChump) ---" << std::endl;
    randomChump("Stacky");
    // 这里你不需要做任何事，Stacky 已经自动被销毁了
    std::cout << "(Stacky should be dead by now)" << std::endl;

    std::cout << "\n--- Testing Heap Allocation (newZombie) ---" << std::endl;
    Zombie* heapZombie = newZombie("Heapo");
    heapZombie->announce(); // 可以自由在外部使用它
    
    // 因为是 new 出来的，所以必须手动 delete 释放堆内存
    delete heapZombie; 
    std::cout << "(Heapo should be dead by now)" << std::endl;


    // std::cout << "\n=== Testing OCF Mechanics ===" << std::endl;
    
    // // 测试 1: 默认构造
    // Zombie genericZombie;
    // genericZombie.announce();

    // // 测试 2: 拷贝构造 (用已有的僵尸克隆一个新僵尸)
    // Zombie clonedZombie(genericZombie); 
    // clonedZombie.announce();

    // // 测试 3: 拷贝赋值运算符
    // Zombie alphaZombie("Alpha");
    // Zombie betaZombie("Beta");
    
    // std::cout << "Before assignment:" << std::endl;
    // betaZombie.announce();
    
    // betaZombie = alphaZombie; // 把 Alpha 的灵魂（数据）赋予 Beta
    
    // std::cout << "After assignment:" << std::endl;
    // betaZombie.announce(); // 此时 betaZombie 的名字应该也变成 Alpha 了

    // std::cout << "\n=== 3. Cleaning Up Automatically ===" << std::endl;
    // // 所有的栈对象（generic, cloned, alpha, beta）将在这里依序隐式触发析构函数

    return 0;
}