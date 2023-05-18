#ifndef ScalarConverter_h
# define ScalarConverter_h
# include<iostream>
# include <exception>
# define  GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define  RESET "\e[0;37m"
# define BLUE  "\033[36m"
# define RED    "\033[0;31m"

class ScalarConverter
{
    public:
        static void    convert(std::string const &str);
    private:
        ScalarConverter   &operator=(ScalarConverter   const &src);
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter   const &src);
};

enum type
{
    INT,
    FLOAT,
    DOUBLE,
    CHAR,
    PSEUDO,
    NON,
};
std::ostream     &operator<<(std::ostream &os, ScalarConverter const &src);


#endif
