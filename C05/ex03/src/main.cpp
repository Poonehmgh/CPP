# include"../inc/Bureaucrat.hpp"
# include"../inc/aForm.hpp"
# include"../inc/ShrubbyCreationForm.hpp"
# include"../inc/RobotomyRequestForm.hpp"
# include"../inc/PresidentialPardonForm.hpp"
# include"../inc/Intern.hpp"

int main()
{
    aForm *form;
    Intern jo;
    Bureaucrat  chef("barak", 1);
    Bureaucrat  officer("donald", 30);

    /*      test for making a shrubby form by intern       */
    form = jo.makeForm("ShrubbyCreationForm", "office");
    /*      test for signing and executing the form pointer handed by intern  */
    chef.signForm(form);
    officer.executeForm(*form);
    chef.executeForm(*form);
    delete form;
    /*      test intern with a wrong form name  */
    aForm   *form2;
    form2 = jo.makeForm("WrongName", "office");
    /*      test intern create other form types     */
    aForm   *form3;
    form3 = jo.makeForm("PresidentialPardonForm", "office");
    // form3 = jo.makeForm("RobotomyRequestForm", "office");
    delete form3;
    return(0);
}