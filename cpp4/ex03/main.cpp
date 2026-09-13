#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
    std::cout << "===== Create MateriaSource =====" << std::endl;
	IMateriaSource *src = new MateriaSource();

    std::cout << "===== Learn Materias =====" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

    std::cout << "===== Create Characters =====" << std::endl;
	ICharacter *me = new Character("me");
    ICharacter *bob = new Character("bob");

    std::cout << "===== Create Materia =====" << std::endl;
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);


	

    std::cout << "===== Use Materia =====" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "===== Cleanup =====" << std::endl;
    delete tmp;
	delete bob;
	delete me;
	delete src;
	return (0);
}