# include "../inc/Form.hpp"
# define YELLOW "\e[1;33m"
# define  RESET "\e[0;37m"

#include"../inc/Bureaucrat.hpp"

Form::Form(): _name_("default"), _signed_(false), _signGrade_(1), _executeGrade_(1)
{
    std::cout << "Default form is made\n";
}

Form::Form(Form const &src)
{
    *this = src;
}

Form::Form(std::string name, int exec, int sgnGrade): _name_(name)
{
    _signed_ = false;
    try
    {
        if (exec > 150 || sgnGrade > 150)
            throw(Form::GradeTooLowException());
        else if (exec < 1 || sgnGrade < 1)
            throw(Form::GradeTooHighException());
        else
        {
            _executeGrade_ = exec; 
            _signGrade_ = sgnGrade;
            std::cout << "The form " << YELLOW << getName() << RESET" with sign grade of " << getSignGrade() << " and execution grade of " << getExecGrade() << "is made. \n";
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << YELLOW"Exception thrown: " << e.what() << '\n';
    }  
}

Form::~Form()
{
    std::cout << "The form " << YELLOW << getName() << RESET << " is torn apart.\n";
}

Form    &Form::operator=(Form   const &src)
{
    _name_ = src.getName();
    _signed_ = src.getSignBool();
    _executeGrade_ = src.getExecGrade();
    _signGrade_ = src.getSignGrade();
    return(*this);
}

std::string Form::getName() const
{
    return(_name_);
}

bool    Form::getSignBool() const
{
    return(_signed_);
}

int Form::getExecGrade() const
{
    return (_executeGrade_);
}

int Form::getSignGrade() const
{
    return(_signGrade_);
}

void    Form::beSigned(Bureaucrat *person)
{
        if (person->getGrade() > getSignGrade())
            throw Form::GradeTooLowException();
        else
            _signed_ = true;
}

std::ostream    &operator<<(std::ostream &os, Form const &src)
{
    return (os << YELLOW << src.getName() << RESET": sign grade: " << src.getSignGrade() <<\
             " execution grade: " << src.getExecGrade() << " is signed?: " << src.getSignBool() << "\n");
}