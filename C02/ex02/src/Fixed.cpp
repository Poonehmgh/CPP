#include"../inc/Fixed.hpp"
#include<cmath>

Fixed::Fixed() {
    _fixPoint_ = 0;
}
Fixed::~Fixed(){}
Fixed::Fixed(const int a)
{
    _fixPoint_ = a << _numFracBits_;
}
Fixed::Fixed(const float a)
{
    _fixPoint_ = roundf(a * (1 <<_numFracBits_));
}
Fixed &Fixed::operator=(Fixed const &src)// i dont know what is the meaning of first handle. ???????
{
    if (this != &src)
    {
        _fixPoint_ = src.getRawBits();
    }
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

bool Fixed::operator>(Fixed const &src) const 
{
    if (src.getRawBits() < getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<(Fixed const &src) const
{
    if (src.getRawBits() > getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator==(Fixed const &src) const 
{
    if (src.getRawBits() == getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator!=(Fixed const &src) const
{
    if (src.getRawBits() != getRawBits())
        return (true);
    return (false);
}

Fixed   Fixed::operator+(Fixed const &src)
{
    this->_fixPoint_ += src.getRawBits();
    return (*this);
}

Fixed   Fixed::operator-(Fixed const &src)
{
    this->_fixPoint_ -= src.getRawBits();
    return (*this);
}

Fixed   Fixed::operator/(Fixed const &src)
{
    this->_fixPoint_ /= src.getRawBits();
    return (*this);
}

Fixed   Fixed::operator*(Fixed const &src)
{
    this->_fixPoint_ *= src.toFloat();
    return (*this);
}

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

Fixed    &Fixed::min(Fixed &m1, Fixed &m2)
{
    if (m1.getRawBits() >= m2.getRawBits())
        return(m2);
    return(m1);
}

Fixed    &Fixed::max(Fixed &m1, Fixed &m2)
{
    if (m1.getRawBits() >= m2.getRawBits())
        return(m1);
    return(m2);
}

const Fixed    &Fixed::min(Fixed const &m1, Fixed const &m2)
{
    if (m1.getRawBits() >= m2.getRawBits())
        return (m2);
    return (m1);
}

const Fixed  &Fixed::max(Fixed  const &m1, Fixed const &m2)
{
    if (m1.getRawBits() >= m2.getRawBits())
        return(m1);
    return(m2);
}
