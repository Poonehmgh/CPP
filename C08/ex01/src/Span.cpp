#include"../inc/Span.hpp"



Span::Span()
{
    _size_ = 0;
}

Span::Span(unsigned int N)
{
    _size_ = N;
}

Span::~Span(){}

Span::Span(Span const &src)
{
    *this = src;
}

Span    &Span::operator=(Span const &src)
{
    _vec_ = src._vec_;
    return(*this);
}

void    Span::addNumber(int N)
{
    if (_vec_.size() < _size_)
        _vec_.push_back(N);
    else
        throw(ExceedSize());
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



