#include"../inc/Fixed.hpp"

Fixed::Fixed() 
{
    std::cout<<"Default constructor is called.\n";
    _fixPoint_ = 0;
}

Fixed::Fixed(int a): _fixPoint_(a){}

Fixed::~Fixed()
{
    std::cout<<"Destructor is called.\n";
}

Fixed &Fixed::operator=(Fixed const &src)
{
    std::cout<<"Copy assignment operator called.\n";
    _fixPoint_ = src.getRawBits();
    return *this;
}

Fixed::Fixed(Fixed const &src)
{
    std::cout<<"Copy constructor called.\n";
    *this = src;
}

int Fixed::getRawBits() const
{
    std::cout<<"getRawBits member function called.\n";
    return (_fixPoint_);
}

void Fixed::setRawBits(int raw)
{
    _fixPoint_ = raw;
}