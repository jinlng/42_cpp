#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
private:
    std::string _name;
    Weapon&     _weapon; // 关键：引用！出生必须初始化，终身不换

    HumanA(); // 故意把默认构造私有化，因为没有武器它无法出生

public:
    HumanA(std::string name, Weapon& weapon); // 正常构造
    HumanA(const HumanA& src);                // OCF 2/4
    HumanA& operator=(const HumanA& rhs);     // OCF 3/4
    ~HumanA();                                // OCF 4/4

    void attack() const;
};

#endif