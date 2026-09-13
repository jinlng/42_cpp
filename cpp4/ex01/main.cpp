#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main(void)
{
    {
        std::cout << "===== TEST 1: Basic objects =====" << std::endl;

        Dog dog;
        Cat cat;

        std::cout << "dog type: " << dog.getType() << std::endl;
        std::cout << "cat type: " << cat.getType() << std::endl;

        dog.makeSound();
        cat.makeSound();

        std::cout << std::endl;

        std::cout << "===== TEST 2: Set Brain ideas =====" << std::endl;

        dog.getBrain()->setIdea(0, "I want to chase cats.");
        dog.getBrain()->setIdea(1, "I want to eat.");
        cat.getBrain()->setIdea(0, "I want to sleep.");

        std::cout << "🐶 dog idea 0: "
                << dog.getBrain()->getIdea(0) << std::endl;

        std::cout << "🐶 dog idea 1: "
                << dog.getBrain()->getIdea(1) << std::endl;

        std::cout << "🐱 cat idea 0: "
                << cat.getBrain()->getIdea(0) << std::endl;

        std::cout << std::endl;

        std::cout << "===== TEST 3: Copy Constructor =====" << std::endl;

        Dog dogCopy(dog);

        std::cout << "original dog idea: "
                << dog.getBrain()->getIdea(0) << std::endl;

        std::cout << "copied dog idea: "
                << dogCopy.getBrain()->getIdea(0) << std::endl;

        std::cout << "same Brain address or not: "
                << (dog.getBrain() == dogCopy.getBrain()) << std::endl;

        std::cout << std::endl;

        std::cout << "===== TEST 4: Modify copied Brain =====" << std::endl;

        dogCopy.getBrain()->setIdea(0, "I want to play.");

        std::cout << "original dog idea: "
                << dog.getBrain()->getIdea(0) << std::endl;

        std::cout << "copied dog idea: "
                << dogCopy.getBrain()->getIdea(0) << std::endl;

        std::cout << std::endl;

        std::cout << "===== TEST 5: Assignment Operator =====" << std::endl;

        Dog dogAssigned;

        dogAssigned.getBrain()->setIdea(0, "Temporary idea.");

        dogAssigned = dog;

        std::cout << "original dog idea: "
                << dog.getBrain()->getIdea(0) << std::endl;

        std::cout << "assigned dog idea: "
                << dogAssigned.getBrain()->getIdea(0) << std::endl;

        std::cout << "same Brain address: "
                << (dog.getBrain() == dogAssigned.getBrain()) << std::endl;

        std::cout << std::endl;

        std::cout << "===== TEST 6: Modify assigned Brain =====" << std::endl;

        dogAssigned.getBrain()->setIdea(0, "New independent idea.");

        std::cout << "original dog idea: "
                << dog.getBrain()->getIdea(0) << std::endl;

        std::cout << "assigned dog idea: "
                << dogAssigned.getBrain()->getIdea(0) << std::endl;

        std::cout << std::endl;
        // All previous tests: stack => return (0) handles all
    }

    std::cout << "===== TEST 7: Delete all in an array =====" << std::endl;

    const int ARRAY_SIZE = 4;
    Animal* animals[ARRAY_SIZE];

    // Heap => must delete in a loop
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i < ARRAY_SIZE / 2) {
            std::cout << "\n[Dogs generating..." << i << "]" << std::endl;
            animals[i] = new Dog();
        } else {
            std::cout << "\n[Cats generating..." << i << "]" << std::endl;
            animals[i] = new Cat();
        }
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << animals[i]->getType() << " [" << i << "]: ";
        animals[i]->makeSound();
    }

    std::cout << "\n--- delete one by one (first Brain then Animal)---" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "\n[killing " << animals[i]->getType() << " " << i << "]" << std::endl;
        delete animals[i]; // expect destructors order: Brain -> Dog/Cat -> Animal
    }

    std::cout << "===== END OF TESTS =====" << std::endl;

    return (0);
}
