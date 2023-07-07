#include"../inc/aMateria.hpp"

aMateria::aMateria(): _type_("default type")
{
    //std::cout << "aMateria default constructor called.\n";
}

aMateria::aMateria(std::string const &type) : _type_(type)
{
    //std::cout << "aMateria constructor called.\n";
}

aMateria::~aMateria()
{
    //std::cout << "aMateria  destructor called.\n";
}

aMateria::aMateria(aMateria const &src)
{
    _type_ = src.getType(); // this is a deep copy, bcz the builin and invisible copy operator of std::string is called here.
    //std::cout << "aMateria copy constructor called.\n";
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