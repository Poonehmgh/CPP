#include"../inc/Span.hpp"



Span::Span() : _size_(0)
{
}

Span::Span(unsigned int N): _size_(N), _index_(0)
{
    _vec_.resize(_size_); // compiler makes the vector of this size and fills it with zeros. 
}

Span::~Span(){}

Span::Span(Span const &src)
{
    *this = src;
}

Span    &Span::operator=(Span const &src)
{
    if (this == &src)
        return (*this);
    _size_ = src._size_; //question here!
    _index_ = src._index_;
    for (unsigned int i = 0; i <= src._index_; i++)
        _vec_.at(i) = src._vec_.at(i);
    return(*this);
}

void    Span::addNumber(int N)
{
    if (_vec_.empty())
        throw(EmptyContainer());
    if (_index_ < _size_)
    {
        _vec_.at(_index_) = N;
        _index_++;
    }
    else
        throw(ExceedSize());
}

int     Span::random_num()
{
    return(std::rand() % INT_MAX);
}

void    Span::fillRandomNumber() // fills the whole vector with ranodm numbers.
{
    if (_vec_.size() > _size_)
        throw(ExceedSize());
    std::generate(_vec_.begin(), _vec_.end(), Span::random_num);
}

int Span::shortestSpan()
{
    std::vector<int> sorted(_vec_.size());
    std::copy(_vec_.begin(), _vec_.end(), sorted.begin()); 
    std::sort(sorted.begin(), sorted.end());
    int min = INT_MAX;
    for(std::vector<int>::iterator i = sorted.begin(); i != sorted.end(); i++)
    {
        if (i + 1 != sorted.end() && *(i + 1) - *i < min)
            min = *(i + 1) - *i;
    }
    return(min);
}

int Span::longestSpan()
{
    if (_vec_.empty())
        throw(EmptyContainer());
    int min_value = *std::min_element(_vec_.begin(), _vec_.end());
    int max_value = *std::max_element(_vec_.begin(), _vec_.end());
    return (max_value - min_value);
}

void    Span::print_vector()
{
    for(std::vector<int>::iterator i = _vec_.begin(); i != _vec_.end(); i++)
        std::cout << GREEN"ELEMENT: " << *i << RESET << std::endl;
}

