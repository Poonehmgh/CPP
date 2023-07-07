#include"../inc/Brain.hpp"

Brain::Brain()
{
    _index_ = 0;
    std::cout << "Brain default constructor called.\n";
}

Brain::~Brain()
{
    std::cout << "Brain destructor called.\n";
}

Brain::Brain(Brain const &src)
{
    *this = src;
    std::cout << "Brain copy constructor called.\n";
}

Brain  &Brain::operator=(Brain const &src)
{
    for (int i = 0; i < src.getIndex(); i++)
        this->setIdea(src.getIdea(i));
    std::cout << "Brain equality operator is called.\n";
    return (*this);
}

std::string Brain::getIdea(int i) const
{
    if (i <= _index_ && i >= 0)
        return(_ideas_[i]);
    else
        std::cout << RED <<"Brain doesnt recall such thing.\n" << RESET;
    return ("No Thought.");
}

void    Brain::setIdea(std::string idea)
{
    if (_index_ >= 100)
    {
        std::cout << RED << "Memory of brain is full! writing over its memories.\n" << RESET;
        _index_ = 0;
    }
    _ideas_[_index_] = idea;
    _index_++;
}

int Brain::getIndex() const
{
    return(_index_);
}