#include"../inc/Bureaucrat.hpp"

int main()
{
    Bureaucrat  peter("Peter", 160);
    Bureaucrat  braian("Braian", 0);
    peter.incrementGrade();
    braian.decrementGrade();
    std::cout << braian;
    return(0);
}