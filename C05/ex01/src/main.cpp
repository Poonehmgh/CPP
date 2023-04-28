#include"../inc/Bureaucrat.hpp"
#include"../inc/Form.hpp"
int main()
{
    Bureaucrat  peter("Peter", 101);
    Form        form("AA12", 100, 100);

    /*              test for signing a form without enough grade      */
    peter.signForm(&form);
    /*              test for incrementing the grade                     */
    peter.incrementGrade();
    /*              test for signing a form with enough grade.          */
    peter.signForm(&form);
    /*              test for << operator for form and bureaucrat       */
    std::cout << form << "\n" << peter;
    return(0);
}