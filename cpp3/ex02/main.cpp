#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
    std::cout << "=== 1. Constructing FragTrap ===" << std::endl;
    FragTrap frag("Fraggy");

    std::cout << "\n=== 2. Testing FragTrap Combat & Abilities ===" << std::endl;
    frag.attack("Target Dummy"); // Uses ClapTrap attack method, but with 30 AD!
    frag.takeDamage(40);
    frag.beRepaired(20);
    frag.highFivesGuys();

    std::cout << "\n=== 3. Trio Arena Battle ===" << std::endl;
    ClapTrap clap("Clappy");
    ScavTrap scav("Serena");

    std::cout << "\n--- Attack Damage Check ---" << std::endl;
    clap.attack("Bandit"); // 0 AD
    scav.attack("Bandit"); // 20 AD
    frag.attack("Bandit"); // 30 AD

    std::cout << "\n=== 4. Destructors Chaining ===" << std::endl;
    return 0;
}
