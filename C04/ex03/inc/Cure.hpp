#ifndef Cure_H
# define Cure_H

#include"../inc/aMateria.hpp"

class Cure : public aMateria
{
    public:
    Cure();
    ~Cure();
    Cure(Cure const &src);
    Cure &operator=(Cure const &src);
    aMateria   *clone() const;
    void    use(iCharacter &target);
};

#endif