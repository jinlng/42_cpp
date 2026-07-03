#include "Zombie.hpp"

#include "Zombie.hpp"

int main() {
    int hordeSize = 7;
    std::string zombieName = "Plante lovers";

    std::cout << "=== Summoning a Horde of " << hordeSize << " Zombies ===" << std::endl;
    
    // 召唤军团，拿到头指针
    Zombie* myHorde = zombieHorde(hordeSize, zombieName);
    
    if (myHorde == NULL) {
        std::cout << "Failed to create a horde." << std::endl;
        return 1;
    }

    std::cout << "\n=== Directing the Horde to Announce ===" << std::endl;
    // 让军团里的每一个僵尸都叫一遍
    for (int i = 0; i < hordeSize; i++) {
        std::cout << "[Index " << i << "] ";
        myHorde[i].announce();
    }

    std::cout << "\n=== Eradicating the Horde (Memory Deallocation) ===" << std::endl;
    // ⚠️ 核心考点：必须用 delete[] 释放对象数组！
    delete[] myHorde;

    std::cout << "=== Simulation End ===" << std::endl;
    return 0;
}