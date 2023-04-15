#include"../inc/Fixed.hpp"
#include<cmath>

Fixed::Fixed()
{
    std::cout<<"Default constructor is called.\n";
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called.\n";
}

Fixed::Fixed(const int a)
{
    std::cout<<"Int constructor called.\n";
    _fixPoint_ = a << _numFracBits_;
}

Fixed::Fixed(const float a)
{
    std::cout<<"Float constructor called.\n";
    _fixPoint_ = roundf(a * (1 <<_numFracBits_)); //why do i round ?
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
    return((int)_fixPoint_/ pow(2, _numFracBits_)); //we turn the fixed point number to its original format in decimal and then we type cast it to an int. 
}

std::ostream &operator<<(std::ostream &ins, Fixed const &src)
{
    ins<<src.toFloat(); //why do we print the float version on the operator << ? because we wanna see the reall value. if we wanted to see the fixed point value, we should have asked getraw to be printed.
    return(ins);
}
