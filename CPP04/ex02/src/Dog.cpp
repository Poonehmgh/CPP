# include "../inc/Dog.hpp"

Dog::Dog()
{
    this->_myBrain_ = new Brain();
    std::cout << "Dog default constructor called. Brain allocated.\n";
}

Dog::Dog(std::string type)
{
    this->setType(type);
    this->_myBrain_ = new Brain();
    std::cout << "Dog constructor called. Brain allocted.\n";
}

Dog::~Dog()
{
    if (_myBrain_)
        delete _myBrain_;
    _myBrain_ = NULL;
    std::cout << "Dog destructor called. Brain deteleted.\n";
}

Dog::Dog(Dog const &src) : aAnimal(src)
{
    *this = src;
    _myBrain_ = new Brain;
    *_myBrain_ = *src._myBrain_;
    std::cout << "Dog copy constructor is called. Brain is allocated.\n";
}

Dog &Dog::operator=(Dog const &src)
{
    this->setType(src.getType());
    std::cout << "Dog copy operator called.\n";
    _myBrain_ = new Brain();
    _myBrain_ = src._myBrain_;
    return(*this);
}

void Dog::makeSound() const
{
    std::cout << getType() << ":" << BLUE <<" Woof Woof!\n" << RESET;
}

void Dog::think(std::string idea)
{
    this->_myBrain_->setIdea(idea);
}

void Dog::sayThoughts(int i)
{
    if ( i < 100 )
        std::cout << BLUE << this->_myBrain_->getIdea(i) << RESET << std::endl;
    else
        std::cout << RED << "I dont have memory of such thing. Out of my brain capacity.\n";
}
