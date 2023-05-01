# include "../inc/ScalarConverter.hpp"
# include <cmath>
int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cerr << RED"error! enter only one argument.\n" << RESET, 1);
    std::string str(argv[1]);
    ScalarConverter instance(str);
    instance.convert();
    // float a = 1099.0f;
    // std::cout <<"\nanother check: " << static_cast<char>(a);
    return (0);
}