#ifndef FIXED_H
# define FIXED_H
#include<iostream>

class Fixed
{
    public:
    Fixed();
    Fixed(const int number);
    Fixed(const float number);
    Fixed(Fixed const &src);
    ~Fixed();
    Fixed &operator=(Fixed const &src);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
    private:
    int _fixPoint_;
    static const int _numFracBits_ = 8;
};

std::ostream &operator<<(std::ostream &ins, Fixed const &src);

#endif