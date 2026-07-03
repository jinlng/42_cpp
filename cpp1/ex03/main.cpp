#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    {
        Weapon club = Weapon("Gata");
        HumanA bob("Bob", club);
        bob.attack();
        
        club.setType("Kanak");
        bob.attack(); // 应该同步变成kanak
    }
    std::cout << "---------------------------------------" << std::endl;
    {
        Weapon club = Weapon("Gata");
        HumanB jim("Jim");
        
        jim.attack(); // 测试没武器状态
        
        jim.setWeapon(club);
        jim.attack();
        
        club.setType("Kanak");
        jim.attack(); // 应该同步变成kanak
    }
    return 0;
}