#include "../inc/rpn.hpp"

int operator_(int a, int b, char c)
{
    if (c == '+')
        return(b + a);
    if (c == '-')
        return(b - a);
    if (c == '*')
        return(a * b);
    return (b / a);
}

int calculator(char **argv)
{
    std::string str(argv[1]);
    std::stack<int> number_stack;

    for (unsigned int i = 0; i < str.size(); i++)
    {
        if (std::isdigit(str.at(i)))
        {
            number_stack.push(str.at(i) - '0');
        }
        else if (str.at(i) == '+' || str.at(i) == '-' || str.at(i) == '/' || str.at(i) == '*')
        {
            if (number_stack.size() < 2)
                throw InvalidOperator();
            else
            {
                int a = number_stack.top();
                number_stack.pop();
                int b = number_stack.top();
                number_stack.pop();
                int c = operator_(a, b, str.at(i));
                number_stack.push(c);
            }
        }
        else if (str.at(i) != ' ')
            throw OnlyDigits();
    }
    if (number_stack.size() != 1)
        throw InvalidOperator();
    return number_stack.top();
}
