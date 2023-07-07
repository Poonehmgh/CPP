# include "../inc/Array.hpp"

// class Awesome
// {
//   public:
//     Awesome(void) : _n(0) {}
//     Awesome( int n ) : _n( n ) {}
//     Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
//     bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
//     bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
//     bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
//     bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
//     bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
//     bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
//     int get_n() const { return _n; }
//   private:
//     int _n;
// };
// std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main( void ) 
{

    /*  call def const on template class */
    try 
    {
        Array<int>  instance(1);
        Array<int> instance2(5);
        instance[0] = 10;
        /*      copy assinment operator and deep copying check */
        instance2 = instance;
        instance.~Array();
        std::cout << GREEN << instance2[0] << RESET<< "\n";
        /*  exceptions check */
        instance2[5] = 20;
        /*  adding more relements which is unacceptable bcz in the beginning we only told to have a certain size of array not more*/
        Array<int> instance3(2);
        for (int i = 0; i < 5; i++)
            instance3[i] = i;    
    }catch (std::exception &e)
    {
        std::cerr << RED"Exception thrown: " << e.what() << RESET << std::endl;
    }
    {
    try{
        /*  another type    */
        Array<std::string>  str_1(5);
        Array<std::string>  str_2(1);
        for (int i = 0; i < 5; i++)
            str_1[i] = "sunny sky";
        str_2[0] = str_1[1];
        std::cout << GREEN << str_2[0] << RESET << std::endl;
        /*  index throw excep    */
        std::cout << str_1[10];
    }catch (std::exception &e)
    {
        std::cerr << RED"Exception thrown: " << e.what() << RESET << std::endl;
    }
    }
    /*      attempt to access an empty array    */
    try
    {
        Array<int>  emptyArray(0);
        std::cout << emptyArray[0];
    }catch (std::exception &e)
    {
        std::cerr << RED"Exception thrown: Empty Array: " << e.what() << RESET << std::endl;
    }
    
    // /*          tests from the eval sheet       */
    // Array<Awesome> a1(2);
    // Awesome a2(5);
    // a1[0] = a2;
    // std::cout << a1[0].get_n();
}
