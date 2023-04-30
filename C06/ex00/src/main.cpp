# include "../inc/ScalarConverter.hpp"
# include <cmath>
int main()
{
    ScalarConverter a("inff");
    a.convert();
    float f = std::numeric_limits<float>::infinity();
    std::cout << "\n POONEH " << static_cast<double>(f) <<std::endl << static_cast<float>(f) << " " << static_cast<int>(f);
    // a.convert("d");
    // std::cout << a.getType() << std::endl;

    // a.convert("hello");
    // std::cout << a.getType() << std::endl;

    // a.convert("7");
    // std::cout << a.getType() << std::endl;


    // a.convert("1.2");
    // std::cout << a.getType() << std::endl;
    // a.convert("55.6");
    // std::cout << a.getType() << std::endl;
    // a.convert("99999.99f");
    // std::cout << a.getType() << std::endl;
    //  a.convert(".f");
    // std::cout << a.getType() << std::endl;
    //  a.convert(".");
    // std::cout << a.getType() << std::endl;
    //  a.convert("1.4f+");
    // std::cout << a.getType() << std::endl;
}