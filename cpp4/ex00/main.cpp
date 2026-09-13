#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WAnimal.hpp"
#include "WCat.hpp"
#include "WDog.hpp"

int main(void)
{
    std::cout << "===== Correct polymorphism =====" << std::endl;

    Animal *a = new Animal();
    Animal *d = new Dog();
    Animal *c = new Cat();

    a->makeSound();
    d->makeSound();
    c->makeSound();

    delete a;
    delete d;
    delete c;

    std::cout << std::endl;
    std::cout << "===== Wrong polymorphism =====" << std::endl;

    WAnimal *wa = new WAnimal();
    WAnimal *wc = new WCat();
    WAnimal *wd = new WDog();

    wa->makeSound();    // Calls WAnimal::makeSound()
    wc->makeSound();    // Calls WAnimal::makeSound()
    wd->makeSound();    // Calls WAnimal::makeSound()

    delete wa;
    delete wc;
    delete wd;

    std::cout << std::endl;
    std::cout << "===== Direct Wrong_[type] call =====" << std::endl;

    WCat direct_cat;
    direct_cat.makeSound(); // Calls WCat::makeSound()
    WDog direct_dog;
    direct_dog.makeSound(); // Calls WDog::makeSound()

    return (0);
}