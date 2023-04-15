#include"../inc/Fixed.hpp"
#include <iostream>

int main (void) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) ); //memory wise, what happens here? is Fixed returning sth?
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    /*      tests for eval  */
    /** test the > and < **/
    if (b > a)
        std::cout<<"b is bigger.\n";
    if (a < b)
        std::cout<<"b is bigger.\n";
    /** test the <= and >=  **/
    if (a >= a)
        std::cout << "1. this is working correctly.\n";
    if (a <= a)
        std::cout << "2. this is working correctly.\n";
    /** test the != and ==  **/

    if (a != b)
        std::cout << "3. this is working correctly.\n";
    if (a == a)
        std::cout << "4. this is working correctly.\n";

    /** test +-* / min max   **/
    Fixed c;
    c.setRawBits(2);
    Fixed d;
    d.setRawBits(3);
    std::cout << "5. answer of c + d should be 5: " << c + d << std::endl;
    std::cout << "6. answer of c - d should be -1: " << c - d << std::endl;
    std::cout << "7. answer of c / c should be 1: " << c / c << std::endl;
    std::cout << "8. answer of c * d should be 6: " << c * d << std::endl;
    std::cout << "9. answer of min (c, d) is 2:" << Fixed::min(c, d) << std::endl;
    std::cout << "10. answer of max (c, d) is 3:" << Fixed::max(c, d) << std::endl;    
    return 0;
}