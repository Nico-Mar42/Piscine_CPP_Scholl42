#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"

int main()
{
	// Création de la source de Materia et apprentissage de Materias
	std::cout << "\033[32m=== Test: Apprentissage des Materias ===\033[0m\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Test de la limite d'apprentissage (doit refuser ou ignorer)
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice()); // Dépasse la limite
	std::cout << std::endl;

	// Création d'un personnage
	std::cout << "\033[32m=== Test: Création et équipement de Materias ===\033[0m\n";
	ICharacter* me = new Character("me");

	// Création et équipement de Materias
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	// Test d'équipement d'un slot déjà plein
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	// Test d'équipement au-delà de la limite (doit être ignoré)
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;

	// Test de l'utilisation des Materias
	std::cout << "\033[32m=== Test: Utilisation des Materias ===\033[0m\n";
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob); // slot vide ou non initialisé
	me->use(3, *bob); // slot vide ou non initialisé
	me->use(4, *bob); // hors limite
	std::cout << std::endl;

	// Test de l'unequip et réutilisation
	std::cout << "\033[32m=== Test: Unequip et réutilisation ===\033[0m\n";
	me->unequip(1);
	me->use(1, *bob); // doit ne rien faire
	std::cout << std::endl;

	// Test de l'unequip hors limite
	std::cout << "\033[32m=== Test: Unequip hors limite ===\033[0m\n";
	me->unequip(4);
	std::cout << std::endl;

	// Test de la copie de Character
	std::cout << "\033[32m=== Test: Copie de Character ===\033[0m\n";
	Character* clone = new Character(*(Character*)me);
	clone->use(0, *bob);
	std::cout << std::endl;

	// Nettoyage
	delete clone;
	delete bob;
	delete me;
	delete src;

	return 0;
}