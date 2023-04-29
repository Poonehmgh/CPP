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

    form = jo.makeForm("ShrubbyCreationForm", "office");
    chef.signForm(form);
    officer.executeForm(*form);
    chef.executeForm(*form);

    delete form;
    return(0);
}