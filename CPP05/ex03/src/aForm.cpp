# include "../inc/aForm.hpp"


#include"../inc/Bureaucrat.hpp"

aForm::aForm(): _name_("default"), _signed_(false), _signGrade_(1), _executeGrade_(1)
{
    std::cout << "Default Form is made\n";
}

aForm::aForm(aForm const &src): _name_(src.getName()), _signed_(src._signed_), _signGrade_(src._signGrade_), _executeGrade_(src._executeGrade_)
{
    *this = src;
    std::cout << "aForm copy constructor called.\n";
}

aForm::aForm(std::string name, int sgnGrade, int exec): _name_(name), _signed_(false), _signGrade_(sgnGrade), _executeGrade_(exec)
{
    try
    {
        if (exec > 150 || sgnGrade > 150)
            throw(aForm::GradeTooLowException());
        else if (exec < 1 || sgnGrade < 1)
            throw(aForm::GradeTooHighException());
        else
        {
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
    std::cout << "aForm copy assignment operator called.";
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

unsigned int aForm::getExecGrade() const
{
    return (_executeGrade_);
}

unsigned int aForm::getSignGrade() const
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

void    aForm::setSignBool(bool s)
{
    _signed_ = s;
}