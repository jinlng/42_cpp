#ifndef WDOG_HPP
#define WDOG_HPP

#include "WAnimal.hpp"

class WDog : public WAnimal
{
public:
    WDog();
    WDog(const WDog &other);
    WDog &operator=(const WDog &other);
    ~WDog();

    void makeSound() const;
};

#endif