#include"../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor called.\n";
    this->setType("WrongAnimal");
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called.\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
    *this = src;
    std::cout << "WrongAnimal copy constructor called.\n";
}

WrongAnimal  &WrongAnimal::operator=(WrongAnimal const &src)
{
    this->_type_ = src.getType();
    std::cout << "WrongAnimal equality operator is called.\n";
    return (*this);
}

void    WrongAnimal::setType(std::string type)
{
    _type_ = type;
}

std::string WrongAnimal::getType(void) const
{
    return (_type_);
}

void    WrongAnimal::makeSound() const
{
    std::cout << "WRONG ANIMAL'S NOISES\n";
}