# include"../inc/PresidentialPardonForm.hpp"
# include<fstream>

PresidentialPardonForm::PresidentialPardonForm() : aForm("PresidentialPardonForm", 25, 5)
{
    _target_ = "default target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : aForm("PresidentialPardonForm", 25, 5)
{
    _target_ = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout <<  YELLOW << getName() << RESET" is torn apart.\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm    const &src) : aForm(src.getName(), src.getSignGrade(), src.getExecGrade()) 
{
    *this = src;
    std::cout << "PresidentialPardonForm copy constrcutor called.\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
    _target_ = src.getTarget();
    return (*this);
}

void    PresidentialPardonForm::executeForm(void) const
{
    std::cout << MAGNETA <<getTarget() << RESET" has been pardoned by Zaphod Beeblebrox.\n";
}

std::string PresidentialPardonForm::getTarget() const
{
    return(_target_);
}

void PresidentialPardonForm::execute(Bureaucrat  const &executor) const
{
    try
    {
        if (!this->getSignBool())
            throw(aForm::FormNotSignedException());
        else if (executor.getGrade() > this->getExecGrade())
            throw (aForm::GradeTooLowException());
        else
            this->executeForm();
        std::cout << "Bureaucrat " << MAGNETA << executor.getName() << RESET" executed " << this->getName() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << YELLOW"Exception thrown: " << e.what() << " PresidentialPardonForm execution faild.\n" << RESET;
    }
}

