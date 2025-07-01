#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);
		virtual ~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const &type);
		void InitMemory();

	private:
		AMateria* _Memory[4];


};

#endif