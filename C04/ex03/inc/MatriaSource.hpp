#ifndef MateriaSource_H
# define MateriaSource_H

#include "aMateria.hpp"
#include "iMatriaSource.hpp"

class MateriaSource: public iMateriaSource
{
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(MateriaSource const &src);
        MateriaSource   &operator=(MateriaSource &src);
        void learnMateria(aMateria*);
        aMateria *createMateria(std::string const &type);
    private:
        aMateria    *_source_[4];
        int        _index_;
};
#endif