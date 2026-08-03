#ifndef WCAT_HPP
# define WCAT_HPP

# include "WAnimal.hpp"

class WCat : public WAnimal
{
public:
    WCat();
    WCat(const WCat &other);
    WCat &operator=(const WCat &other);
    ~WCat();

    void makeSound() const;
};

#endif