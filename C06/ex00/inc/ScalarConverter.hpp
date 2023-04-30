#ifndef ScalarConverter_h
# define ScalarConverter_h
# include<iostream>
# include <exception>
# define  GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define  RESET "\e[0;37m"
# define BLUE  "\033[36m"

class ScalarConverter
{
    public:
        ScalarConverter(std::string input);
        virtual ~ScalarConverter();
        ScalarConverter(ScalarConverter   const &src);
        ScalarConverter   &operator=(ScalarConverter   const &src);
        void    convert();
        int     findType(std::string s);
        void    setType(int a);
        int     getType() const;
        void    toInt();
        int     int_;
        float   float_;
        char    char_;
        double  double_;
        void    handle_int();
        void    handle_float();
        void    handle_double();
        void    handle_char();
        void    handle_in();
    private:
        int     _type_;
        std::string _string_;
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
