# include "../inc/Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called.\n";
}

Cat::~Cat()
{
    std::cout << "Cat destructor called.\n";
}

Cat::Cat(Cat const &src)
{
    *this = src;
    std::cout << "Cat copy constructor is called.\n";
}

Cat &Cat::operator=(Cat const &src)
{
    this->setType(src.getType());
    std::cout << "Cat copy operator called.\n";
    return(*this);
}

Cat::Cat(std::string type)
{
    setType(type); //this overwrites the "animal type" that was set by animal default constructor. 
    std::cout << "Cat constructor is called.\n";
}

void Cat::makeSound() const
{
    std::cout << getType() << ":" << RED << " Meaoooow! \n" << RESET;
}