#include "../inc/Ice.hpp"

Ice::Ice() : aMateria("ice")
{
}

Ice::Ice(Ice const &src)
{
    _type_ = src.getType();
}

Ice::~Ice()
{
}

Ice &Ice::operator=(Ice const &src)
{
    _type_ = src.getType();
    return (*this);
}

aMateria *Ice::clone() const
{
    Ice *ret = new Ice();
    ret->_type_ = _type_;
    return (ret);
}

void Ice::use(iCharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}