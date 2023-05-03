# include "../inc/Iter.hpp"


int main( void ) 
{
    std::string array1[3] = {"hello", "world!", ":)\n"};
    iter<std::string, 3, &print<std::string> >(array1, 3);
    float array2[5] = {1.2f, 3.3333f, 0.0007f, 78, .2f};
    iter<float, 5, &print<> >(array2, 5);
    std::cout << "\n";
    return 0;
}