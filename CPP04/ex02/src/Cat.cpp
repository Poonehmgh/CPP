# include "../inc/Cat.hpp"

Cat::Cat()
{
    this->_myBrain_ = new Brain();
    std::cout << "Cat default constructor called. Brain allocated.\n";
}

Cat::~Cat()
{
   if (_myBrain_)
        delete _myBrain_;
    _myBrain_ = NULL;
    std::cout << "Cat destructor called. Brain deleted.\n";
}

Cat::Cat(Cat const &src) : aAnimal(src)
{
    *this = src;
    _myBrain_ = new Brain;
    *_myBrain_ = *src._myBrain_;
    std::cout << "Cat copy constructor is called. Brain is allocated.\n";
}

Cat &Cat::operator=(Cat const &src)
{
    this->setType(src.getType());
    std::cout << "Cat copy operator called.\n";
    _myBrain_ = new Brain();
    _myBrain_ = src._myBrain_;
    return(*this);
}

Cat::Cat(std::string type)
{
    this->_myBrain_ = new Brain();
    this->setType(type);
    std::cout << "Cat constructor is called. Brain is allocated\n";
}

void Cat::makeSound() const
{
    std::cout << getType() << ":" << RED << " Meaoooow! \n" << RESET;
}

void Cat::think(std::string idea)
{
    this->_myBrain_->setIdea(idea);
}

void Cat::sayThoughts(int i)
{
    if (i < 100)
        std::cout << BLUE << this->_myBrain_->getIdea(i) << RESET << std::endl;
    else
        std::cout << RED << "I dont have memory of such thing. Out of my brain capacity.\n";
}