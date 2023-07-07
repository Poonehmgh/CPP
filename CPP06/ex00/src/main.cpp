# include "../inc/ScalarConverter.hpp"
# include <cmath>

int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cerr << RED"error! enter only one argument.\n" << RESET, 1);
    std::string str(argv[1]);
    ScalarConverter::convert(str); // since its static, it allows us to use it as a utility, without having to instantiate an object on it. 
    return (0);
}