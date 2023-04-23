# include "../inc/WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor called.\n";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called.\n";
}

WrongCat::WrongCat(WrongCat const &src)
{
    *this = src;
    std::cout << "WrongCat copy constructor is called.\n";
}

WrongCat &WrongCat::operator=(WrongCat const &src)
{
    this->setType(src.getType());
    std::cout << "WrongCat copy operator called.\n";
    return(*this);
}

WrongCat::WrongCat(std::string type)
{
    this->setType(type); //this overwrites the "animal type" that was set bu animal default constructor. 
    std::cout << "WrongCat constructor is called.\n";
}

void WrongCat::makeSound() const
{
    std::cout << getType() << ":" << RED << " SOME NOISE FOR WRONG CAT! \n" << RESET;
}