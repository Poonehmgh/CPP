#include"../inc/Fixed.hpp"
#include<cmath>

Fixed::Fixed() {
    _fixPoint_ = 0;
}

Fixed::~Fixed(){}

Fixed::Fixed(const int a)
{
    setRawBits(a << _numFracBits_);
}

Fixed::Fixed(const float a)
{
    _fixPoint_ = roundf(a * (1 <<_numFracBits_));
}

Fixed &Fixed::operator=(Fixed const &src)
{
    _fixPoint_ = src.getRawBits();
    return *this;
}

Fixed::Fixed(Fixed const &src)
{
    *this = src;
}

int Fixed::getRawBits() const
{
    return(_fixPoint_);
}

void Fixed::setRawBits(int raw)
{
    _fixPoint_ =  raw;
}

float Fixed::toFloat(void) const
{
    return (((float)_fixPoint_) / (1 << _numFracBits_));
}

int Fixed::toInt(void) const
{
    return(_fixPoint_ >> _numFracBits_);
}

/*****************************COMPARISON OPERATORS********************/

std::ostream &operator<<(std::ostream &ins, Fixed const &src)
{
    ins<<src.toFloat();
    return(ins);
}

bool Fixed::operator>(Fixed const &src) const 
{
    return (src.getRawBits() < getRawBits());
}

bool Fixed::operator<(Fixed const &src) const
{
    return (src.getRawBits() > getRawBits());
}

bool Fixed::operator==(Fixed const &src) const 
{
    return (src.getRawBits() == getRawBits());
}

bool Fixed::operator!=(Fixed const &src) const
{
    return (src.getRawBits() != getRawBits());
}

bool Fixed::operator>=(Fixed const &src) const
{
    return (getRawBits() >= src.getRawBits());
}

bool Fixed::operator<=(Fixed const &src) const
{
    return (getRawBits() <= src.getRawBits());
}
/***********************ARITHMETIC OPERATORS********************************/

Fixed   Fixed::operator+(Fixed const &src)
{
    Fixed result;
    result.setRawBits((_fixPoint_ + src.getRawBits()));
    return result;
}

Fixed   Fixed::operator-(Fixed const &src)
{
    Fixed tmp;
    tmp.setRawBits(getRawBits() - src.getRawBits());
    return (tmp);
}

Fixed   Fixed::operator/(Fixed const &src)
{
    Fixed   tmp(this->toFloat() / src.toFloat()); //not working without float.
    return (tmp);
}

Fixed   Fixed::operator*(Fixed const &src)
{
    Fixed tmp;
    tmp.setRawBits(getRawBits() * src.getRawBits() >> _numFracBits_);
    return (tmp);
}
/********************************INCREMENT/DECREMENT OPERATORS************/
Fixed   Fixed::operator++(void)
{
    _fixPoint_++;
    return (*this);
}

Fixed   Fixed::operator--(void)
{
    _fixPoint_--;
    return (*this);
}

Fixed   Fixed::operator++(int) //dummy int for post-increment operator
{
    Fixed   instance(*this);
    _fixPoint_++;
    return (instance);
}

Fixed   Fixed::operator--(int)
{
    Fixed   instance(*this);
    _fixPoint_--;
    return (instance);
}
/****************************** MIN/MAX ********************************/

Fixed    &Fixed::min(Fixed &m1, Fixed &m2)
{
    if (m1.toFloat() >= m2.toFloat())
        return(m2);
    return(m1);
}

Fixed    &Fixed::max(Fixed &m1, Fixed &m2)
{
    if (m1.toFloat() >= m2.toFloat())
        return(m1);
    return(m2);
}

const Fixed    &Fixed::min(Fixed const &m1, Fixed const &m2)
{
    if (m1.toFloat() >= m2.toFloat())
        return (m2);
    return (m1);
}

const Fixed  &Fixed::max(Fixed  const &m1, Fixed const &m2)
{
    if (m1.toFloat() >= m2.toFloat())
        return(m1);
    return(m2);
}
