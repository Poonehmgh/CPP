#ifndef FIXED_H
# define FIXED_H
#include<iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(int fixPoint);
        Fixed(Fixed const &src);
        ~Fixed();
        Fixed   &operator=(Fixed const &src);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
    private:
        int _fixPoint_;
        static const int _numFracBits_;
};


#endif