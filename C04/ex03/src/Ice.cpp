#include "../inc/Ice.hpp"

Ice::Ice() : aMateria("ice")
{
    //std::cout << "Ice default constructor called.\n";
}

Ice::Ice(Ice const &src)
{
    //std::cout << "Ice copy constructor called.\n";
    _type_ = src.getType();
}

Ice::~Ice()
{
    //std::cout << "Ice  destructor called.\n";
}

Ice &Ice::operator=(Ice const &src)
{
    _type_ = src.getType();
    //std::cout << "Ice copy operator called.\n";
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