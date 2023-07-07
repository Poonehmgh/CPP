#include "../inc/Cure.hpp"

Cure::Cure() : aMateria("cure")
{
    //std::cout << "Cure default constructor called.\n";
}

Cure::Cure(Cure const &src)
{
    //std::cout << "Cure copy constructor called.\n";
    _type_ = src.getType();
}

Cure::~Cure()
{
    //std::cout << "Cure  destructor called.\n";
}

Cure    &Cure::operator=(Cure const &src)
{
    //std::cout << "Cure copy operator called.\n";
    _type_ = src.getType();
    return(*this);
}

aMateria *Cure::clone() const
{
    Cure *ret = new Cure();
    ret->_type_ = _type_;
    return (ret);
}

void Cure::use(iCharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}