#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    std::cout << "=== 1. Constructing ScavTrap ===" << std::endl;
    ScavTrap scav("Serena");

    std::cout << "\n=== 2. Testing ScavTrap Attacks & Skills ===" << std::endl;
    scav.attack("Handsome Jack");
    scav.takeDamage(30);
    scav.beRepaired(15);
    scav.guardGate();

    std::cout << "\n=== 3. Comparing with Base ClapTrap ===" << std::endl;
    ClapTrap clap("Basic_Clap");
    clap.attack("Handsome Jack"); // ClapTrap deals 0 damage, ScavTrap deals 20

    std::cout << "\n=== 4. Destructors Chaining ===" << std::endl;
    return 0;
}
