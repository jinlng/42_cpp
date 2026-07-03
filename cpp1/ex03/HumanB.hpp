#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB {
private:
    std::string _name;
    Weapon* _weapon; // 关键：指针！可以为 NULL，中途可以换

public:
    HumanB();                             // OCF 1/4
    HumanB(std::string name);
    HumanB(const HumanB& src);            // OCF 2/4
    HumanB& operator=(const HumanB& rhs); // OCF 3/4
    ~HumanB();                            // OCF 4/4

    void setWeapon(Weapon& weapon);
    void attack() const;
};

#endif