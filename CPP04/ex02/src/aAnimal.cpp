#include"../inc/aAnimal.hpp"

aAnimal::aAnimal()
{
    std::cout << "aAnimal default constructor called.\n";
    this->setType("aAnimal");
}

aAnimal::~aAnimal()
{
    std::cout << "aAnimal destructor called.\n";
}

aAnimal::aAnimal(aAnimal const &src)
{
    *this = src;
    std::cout << "aAnimal copy constructor called.\n";
}

aAnimal  &aAnimal::operator=(aAnimal const &src)
{
    this->_type_ = src.getType();
    std::cout << "aAnimal equality operator is called.\n";
    return (*this);
}

void    aAnimal::setType(std::string type)
{
    _type_ = type;
}

std::string aAnimal::getType(void) const
{
    return (_type_);
}

void    aAnimal::makeSound() const
{
    std::cout << "Some Animal sound here!\n";
}