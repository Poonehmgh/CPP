# include "../inc/Iter.hpp"

/*      test from eval sheet    */
// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

// template< typename T >
// void print( T const & x ) { std::cout << x << std::endl; return; }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }


int main( void )
{
    std::string array1[3] = {"hello", "world!", ":)\n"};
    iter(array1, 3, print_);
    float array2[5] = {1.2f, 3.3333f, 0.0007f, 78, .2f};
    iter(array2, 5, print_<float>); //function pointer can be passed both as explicitly saying the input type and the implicit form.
    std::cout << "\n";
    return 0;
}
