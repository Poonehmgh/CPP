# include"../inc/Intern.hpp"
# include<fstream>
# include"../inc/ShrubbyCreationForm.hpp"
# include"../inc/RobotomyRequestForm.hpp"
# include "../inc/PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "The poor intern is here.\n";
}


Intern::~Intern()
{
    std::cout << "Intern is gone.\n";
}

Intern::Intern(Intern    const &src)
{
    *this = src;
}

Intern &Intern::operator=(Intern const &src)
{
    _target_ = src.getTarget();
    _name_ = getFormName();
    return (*this);
}

std::string Intern::getFormName() const
{
    return(_name_);
}

std::string Intern::getTarget() const
{
    return(_name_);
}

aForm   *Intern::makeForm(std::string name, std::string target)
{
    std::string array[3] = {"ShrubbyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    aForm   *(Intern::*func_ptr[3])(std::string) = {&Intern::makeShrubberyForm, &Intern::makeRobotomyForm, &Intern::makePardonForm}; //the syntax
    int     i = 0;

    while (i < 3)
    {
        if (array[i] == name)
        {
            std::cout << GREEN"Intern creates " << name << RESET".\n";
            return ((this->*func_ptr[i])(target));
        }
        i++;
    }
    std::cout << YELLOW"Invalid form name " << RESET"\n";
    return (NULL);
}

aForm   *Intern::makeShrubberyForm(std::string target)
{
    return (new ShrubbyCreationForm(target));
}

aForm   *Intern::makeRobotomyForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

aForm   *Intern::makePardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}
