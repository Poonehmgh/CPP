#include "../inc/Cure.hpp"

Cure::Cure() : aMateria("cure")
{
}

Cure::Cure(Cure const &src)
{
    _type_ = src.getType();
}

Cure::~Cure()
{
}

Cure    &Cure::operator=(Cure const &src)
{
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