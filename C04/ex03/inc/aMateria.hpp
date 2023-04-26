#ifndef AMATERIA_H
# define AMATERIA_H

#include<iostream>
#include "iCharacter.hpp"
class iCharacter;
class aMateria
{
    public:
        aMateria(std::string const &type);
        aMateria();
        virtual ~aMateria(); // the destructor in absrtact classes must be virtual to avoid leaking.
        aMateria(aMateria const &src);
        aMateria    &operator=(aMateria const &src);
        std::string const &getType() const;
        virtual aMateria    *clone() const = 0;
        virtual void use(iCharacter &target) = 0;
    protected:
        std::string _type_;
};


#endif