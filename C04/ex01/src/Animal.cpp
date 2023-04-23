#include"../inc/Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called.\n";
    this->setType("Animal");
}

Animal::~Animal()
{
    std::cout << "Animal destructor called.\n";
}

Animal::Animal(Animal const &src)
{
    *this = src;
    std::cout << "Animal copy constructor called.\n";
}

Animal  &Animal::operator=(Animal const &src)
{
    this->_type_ = src.getType();
    std::cout << "Animal equality operator is called.\n";
    return (*this);
}

void    Animal::setType(std::string type)
{
    _type_ = type;
}

std::string Animal::getType(void) const
{
    return (_type_);
}

void    Animal::makeSound() const
{
    std::cout << "Some animal sound here!\n";
}