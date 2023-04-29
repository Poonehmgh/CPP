# include"../inc/Bureaucrat.hpp"
# include"../inc/aForm.hpp"
# include"../inc/ShrubbyCreationForm.hpp"
# include"../inc/RobotomyRequestForm.hpp"
# include"../inc/PresidentialPardonForm.hpp"

int main()
{
    ShrubbyCreationForm formA("home");
    RobotomyRequestForm formB("garage");
    PresidentialPardonForm formC("home");

    Bureaucrat  officer("Briaian", 100);
    Bureaucrat  chef("Peter", 1);
    Bureaucrat  middleManager("Stewee", 45);

    /*      signing forms first     */
    officer.signForm(&formA); //officer can sign this form
    officer.signForm(&formB); //officer cant sign this form
    // middleManager.signForm(&formB);
    /*      executing the forms     */
    officer.executeForm(formA);  //officer can execute the signed form
    middleManager.executeForm(formB);   //manager cant execute this form because it is not signed.
    middleManager.signForm(&formB);    // formB is signed here.
    officer.executeForm(formB);         //officer cannot execute the form because of his low grade.
    middleManager.executeForm(formB);   //manager should be able to execute the form.
    chef.signForm(&formC);
    chef.executeForm(formC);



    return(0);
}