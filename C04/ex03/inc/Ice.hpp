#ifndef ICE_H
# define ICE_H

#include"../inc/aMateria.hpp"

class Ice : public aMateria
{
    public:
        Ice();
        ~Ice();
        Ice(Ice const &src);
        Ice &operator=(Ice const &src);
        aMateria   *clone() const;
        void use(iCharacter &target);
};

#endif