#include"../inc/aMateria.hpp"

aMateria::aMateria(): _type_("default type")
{
}

aMateria::aMateria(std::string const &type) : _type_(type)
{
}

aMateria::~aMateria()
{
}

aMateria::aMateria(aMateria const &src)
{
    _type_ = src.getType(); // this is a deep copy, bcz the builin and invisible copy operator of std::string is called here.
}

aMateria    &aMateria::operator=(aMateria   const &src)
{
    _type_ = src.getType();
    return (*this);
}

std::string    const &aMateria::getType() const
{
    return(_type_);
}

// void aMateria::use(iCharacter &target) either this, or make it pure virtual in aMateria class.
// {
//     (void)target;
// }