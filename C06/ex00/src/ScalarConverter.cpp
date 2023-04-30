# include "../inc/ScalarConverter.hpp"
# include <string>
# include <cctype>
# include <limits.h>

ScalarConverter::ScalarConverter(std::string input) : _string_(input)
{
    std::cout << "Default ScalarConverter constructor is called.\n";
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor is called.\n";
}

ScalarConverter::ScalarConverter(ScalarConverter   const &src)
{
    *this = src;
}

ScalarConverter  &ScalarConverter::operator=(ScalarConverter   const &src)
{
    _type_ = src.getType();
    return(*this);
}


int    ScalarConverter::findType(std::string s)
{
    if (s.length() == 1 && !isdigit(s.at(0)))
        return (CHAR);
    if (s == "+inff" || s == "+INFF" || s == "-inff" || s == "-INFF" || s == "nanf")
        return(PSEUDO);
    for(size_t i = 0; i < s.length(); i++)
    {
        if (!isdigit(s.at(i)) && s.at(i) != '.' && s.at(i) != 'f' && s.at(i) != '+' && s.at(i) != '-')
            return (NON);
    }
    if (s.find('.') != std::string::npos)
    {
        if (s.find('f') != std::string::npos)
            return (FLOAT);
        return (DOUBLE);
    }
    return (INT);
}


void    ScalarConverter::convert()
{
    setType(findType(_string_));
    long tmp = atol(_string_.c_str());
    switch (getType())
    {
        case 0:
            if (tmp > std::numeric_limits<int>::max() ||  tmp < std::numeric_limits<int>::min())
            {
                int_ = std::numeric_limits<int>::min();
                _type_ = FLOAT;
                handle_int();
            }
            else
            {
                int_ = atoi(_string_.c_str());
                handle_int();
                break;
            }
        case 1:
            float_ = atof(_string_.c_str());
            handle_float();
            break;
        case 2:
            double_ = atof(_string_.c_str());
            handle_double();
            break;
        case 3:
            char_ = _string_.at(0);
            handle_char();
            break;
        case 4:
            handle_in();
            break;  
    }
    std::cout << *this;
}

void ScalarConverter::setType(int a)
{
    _type_ = a;
}

int ScalarConverter::getType() const
{
    return(_type_);
}

std::ostream     &operator<<(std::ostream &os,ScalarConverter const &src)
{
    // if (src.getType() == PSEUDO)
    //     return (os << "")
    if (src.char_ > 32 && src.char_ < 127)
        return (os << YELLOW"char: '" <<  src.char_ << "' "<< GREEN"int: " << src.float_ << BLUE" float: " << src.int_ << YELLOW" double: " << src.double_ << RESET"\n");
    else
        return (os << YELLOW"char: not visible " << GREEN"int: " << src.int_ << BLUE" float: " << src.float_ << YELLOW" double: " << src.double_ << RESET"\n");      
}

void ScalarConverter::handle_int()
{
    float_ = static_cast<float>(int_);
    double_ = static_cast<double>(int_);
    char_ = static_cast<char>(int_);
}

void ScalarConverter::handle_float()
{
    double_ = static_cast<double>(float_);
    char_ = static_cast<char>(float_);
    if (float_ > INT_MAX || float_ < INT_MIN)
    {
        std::cout << "Int not valid.\n";
        int_ = INT_MIN;
        return ;
    }
    int_ = static_cast<int>(float_);
}

void ScalarConverter::handle_double()
{
    float_ = static_cast<float>(double_);
    char_ = static_cast<char>(double_);
    if (double_ > INT_MAX || double_ < INT_MIN)
    {
        std::cout << "Int not valid.\n";
        int_ = INT_MIN;
        return ;
    }
    int_ = static_cast<int>(double_);
}

void ScalarConverter::handle_char()
{
    float_ = static_cast<float>(char_);
    double_ = static_cast<double>(char_);
    int_ = static_cast<int>(char_);
}

// void ScalarConverter::handle_in() // check infitiy and nan 
// {
//     if (_string_.at(0) == '-')
//         float_ = std::numeric_limits<float>::infinity();
//     else
//         float_ = std::numeric_limits<float>::infinity();
//     // float_ = static_cast<float>(atof(_string_.c_str()));
//     double_ = static_cast<double>(float_);
//     int_ = INT_MIN;
// }