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
    Fixed   &operator=(Fixed const &src);
    Fixed   operator+(Fixed const &src);
    Fixed   operator-(Fixed const &src);
    Fixed   operator/(Fixed const &src);
    Fixed   operator*(Fixed const &src);
    Fixed   operator++(void);
    Fixed   operator--(void);
    Fixed   operator++(int);
    Fixed   operator--(int);
    static Fixed    &min(Fixed &m1, Fixed &m2);
    static Fixed    &max(Fixed &m1, Fixed &m2);
    static Fixed    const &min(Fixed const &m1, Fixed const &m2);
    static Fixed    const &max(Fixed const &m1, Fixed const &m2);
    bool    operator>(Fixed const &src) const;
    bool    operator<(Fixed const &src) const;
    bool    operator==(Fixed const &src) const;
    bool    operator>=(Fixed const &src) const;
    bool    operator<=(Fixed const &src) const;
    bool    operator!=(Fixed const &src) const;
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