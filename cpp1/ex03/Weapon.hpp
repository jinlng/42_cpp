#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
private:
    std::string _type;

public:
    Weapon();                             // OCF 1/4
    Weapon(std::string type);
    Weapon(const Weapon& src);            // OCF 2/4
    Weapon& operator=(const Weapon& rhs); // OCF 3/4
    ~Weapon();                            // OCF 4/4

    const std::string& getType() const;
    void setType(std::string newType);
};

#endif