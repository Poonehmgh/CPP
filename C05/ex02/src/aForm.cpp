# include "../inc/aForm.hpp"


#include"../inc/Bureaucrat.hpp"

aForm::aForm(): _name_("default"), _signed_(false), _signGrade_(1), _executeGrade_(1)
{
    std::cout << "Default Form is made\n";
}

aForm::aForm(aForm const &src)
{
    *this = src;
}

aForm::aForm(std::string name, int exec, int sgnGrade): _name_(name)
{
    _signed_ = false;
    try
    {
        if (exec > 150 || sgnGrade > 150)
            throw(aForm::GradeTooLowException());
        else if (exec < 1 || sgnGrade < 1)
            throw(aForm::GradeTooHighException());
        else
        {
            _executeGrade_ = exec; 
            _signGrade_ = sgnGrade;
            std::cout << "The Form " << YELLOW << getName() << RESET" with sign grade of " << getSignGrade() << " and execution grade of " << getExecGrade() << " is made. \n";
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << YELLOW"Exception thrown: " << e.what() << '\n';
    }  
}

aForm::~aForm()
{
    std::cout << "The Form " << YELLOW << getName() << RESET << " is torn apart.\n";
}

aForm    &aForm::operator=(aForm   const &src)
{
    _name_ = src.getName();
    _signed_ = src.getSignBool();
    _executeGrade_ = src.getExecGrade();
    _signGrade_ = src.getSignGrade();
    return(*this);
}

std::string aForm::getName() const
{
    return(_name_);
}

bool    aForm::getSignBool() const
{
    return(_signed_);
}

int aForm::getExecGrade() const
{
    return (_executeGrade_);
}

int aForm::getSignGrade() const
{
    return(_signGrade_);
}

void    aForm::beSigned(Bureaucrat *person)
{
        if (person->getGrade() > getSignGrade())
            throw aForm::GradeTooLowException();
        else
            _signed_ = true;
}

std::ostream    &operator<<(std::ostream &os, aForm const &src)
{
    return (os << YELLOW << src.getName() << RESET": sign grade: " << src.getSignGrade() <<\
             " execution grade: " << src.getExecGrade() << " is signed?: " << src.getSignBool() << "\n");
}