#include"../inc/Fixed.hpp"

Fixed::Fixed() { std::cout<<"Default constructor is called.\n";}
Fixed::Fixed(int a): _fixPoint_(0){}
Fixed::~Fixed(){std::cout<<"Deconstructor is called.\n";}
Fixed &Fixed::operator=(Fixed const &src) // i dont know what is the meaning of first handle. ???????
{
    std::cout<<"Copy assignment operator called.\n";
    if (this != &src)
    {
        _fixPoint_ = src.getRawBits();
    }
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
}
void Fixed::setRawBits(int raw)
{
    _fixPoint_ = raw;
}