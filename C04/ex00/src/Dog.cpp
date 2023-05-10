# include "../inc/Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called.\n";
}

Dog::Dog(std::string type)
{
    setType(type);
    std::cout << "Dog constructor called.\n";
}

Dog::~Dog()
{
    std::cout << "Dog destructor called.\n";
}

Dog::Dog(Dog const &src)
{
    *this = src;
    std::cout << "Dog copy constructor is called.\n";
}

Dog &Dog::operator=(Dog const &src)
{
    setType(src.getType());
    std::cout << "Dog copy operator called.\n";
    return(*this);
}

void Dog::makeSound() const
{
    std::cout << getType() << ":" << BLUE <<" Woof Woof!\n" << RESET;
}