#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    std::cout << "\n ===== POLYMORPHISM ===== \n" << std::endl;
    // Create dynamic instances of Dog and Cat using AAnimal pointers
    AAnimal *dog = new Dog();
    AAnimal *cat = new Cat();

    std::cout << "Dog type: "
              << dog->getType() << std::endl;

    std::cout << "Cat type: "
              << cat->getType() << std::endl;

    std::cout << std::endl;
    
    // Call makeSound() on both objects to demonstrate polymorphism
    dog->makeSound();
    cat->makeSound();

    std::cout << std::endl;

    delete dog;
    delete cat;

    std::cout << "\n ===== Deep Copy Test ===== \n" << std::endl;

    Dog dog1;

    dog1.getBrain()->setIdea(0, "Original idea");

    Dog dog2(dog1);

    std::cout << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << dog2.getBrain()->getIdea(0) << std::endl;
    // Check if the Brain pointers are different
    std::cout << "Same brain: "
              << (dog1.getBrain() == dog2.getBrain())
              << std::endl;
    // Modify the idea in dog2's brain and check if it affects dog1's brain
    dog2.getBrain()->setIdea(0, "Modified idea");
    // Print the ideas again to see if they are independent
    std::cout << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << dog2.getBrain()->getIdea(0) << std::endl;



    return (0);
}