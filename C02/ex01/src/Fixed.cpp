#include"../inc/Fixed.hpp"
#include<cmath>

Fixed::Fixed() { std::cout<<"Default constructor is called.\n";}
Fixed::~Fixed(){std::cout<<"Deconstructor called.\n";}
Fixed::Fixed(const int a)
{
    std::cout<<"Int constructor called.\n";
    _fixPoint_ = a << _numFracBits_;
}
Fixed::Fixed(const float a)
{
    std::cout<<"Float constructor called.\n";
    _fixPoint_ = roundf(a * (1 <<_numFracBits_));
}
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
    return(_fixPoint_);
}
void Fixed::setRawBits(int raw)
{
    _fixPoint_ = raw;
}
float Fixed::toFloat(void) const
{
    return ((float)_fixPoint_ / pow(2, _numFracBits_));
}
int Fixed::toInt(void) const
{
    return((int)_fixPoint_/ pow(2, _numFracBits_));
}
std::ostream &operator<<(std::ostream &ins, Fixed const &src)
{
    ins<<src.toFloat(); //why ? why not getraw? 
    return(ins);
}
