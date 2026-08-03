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

    wa->makeSound();
    wc->makeSound();   // Calls WrongAnimal::makeSound()

    delete wa;
    delete wc;

    std::cout << std::endl;
    std::cout << "===== Direct WrongCat call =====" << std::endl;

    WCat direct;
    direct.makeSound(); // Calls WrongCat::makeSound()

    return (0);
}