#ifndef IMateriaSource_H
# define IMateriaSource_H

#include "aMateria.hpp"

class iMateriaSource
{
    public:
        virtual ~iMateriaSource() {}
        virtual void learnMateria(aMateria*) = 0;
        virtual aMateria *createMateria(std::string const & type) = 0;
};
#endif