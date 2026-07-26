#include "DiamondTrap.hpp"

int main(void) {
    std::cout << "=== 1. Constructing DiamondTrap ===" << std::endl;
    DiamondTrap dia("Monster");

    std::cout << "\n=== 2. Identity & Special Ability Check ===" << std::endl;
    dia.whoAmI();

    std::cout << "\n=== 3. Combat & Inherited Skills Check ===" << std::endl;
    dia.attack("Handsome Jack"); // Should use ScavTrap's attack
    dia.guardGate();             // From ScavTrap
    dia.highFivesGuys();         // From FragTrap

    std::cout << "\n=== 4. Stats Verification ===" << std::endl;
    dia.takeDamage(30);          // Testing HP (starts at 100)
    dia.beRepaired(20);

    std::cout << "\n=== 5. Destructors Chaining ===" << std::endl;
    return 0;
}