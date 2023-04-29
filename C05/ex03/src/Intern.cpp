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
    aForm   *form;
    int     i;

    for (i = 0; i < 4; i++)
        if (array[i] == name)
            break;
    switch (i)
    {
    case 0:
        form = new ShrubbyCreationForm(target);
        break;
    case 1:
        form = new RobotomyRequestForm(target);
        break;
    case 2:
        form = new PresidentialPardonForm(target);
        break;
    // default:
    //     std::cout << "Invalid form name\n";
    //     form = NULL;
    //     break;
    }
    if (form)
        std::cout << "Intern creates " << form->getName() << "\n";
    return (form);
}