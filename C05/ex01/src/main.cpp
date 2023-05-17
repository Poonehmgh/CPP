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
    /*              test for copy operator to see its behaviour for the const parts  */
    Form    A;
    A = form;
    std::cout << A; // we see that the only attribute of form which is copied to A, is its boolean for sign.
    /*              test for grade constraints in form class            */
    Form    B("b", 200, 1);
    Form    C("c", 0, 100);
    Form    D("d", -1, 300);
    return(0);
}