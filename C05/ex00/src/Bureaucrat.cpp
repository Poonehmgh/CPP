# include "../inc/Bureaucrat.hpp"
# define  GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define  RESET "\e[0;37m"
Bureaucrat::Bureaucrat(): _name_("default")
{
    std::cout << "Default Bureaucrat is made.\n";
    _grade_ = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name_(name)
{
    try
    {
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else
        {
            _grade_ = grade;
            std::cout << "Bureaucrat " << GREEN << getName() << RESET <<" with grade " << getGrade() << " is made.\n";
        }

    } catch (const std::exception &e)
    {
        std::cerr << YELLOW"Exception thrown: " << RESET<< e.what();
        _grade_ = 150;
        std::cout << "Bureaucrat " << GREEN << getName() << RESET" with grade " << getGrade() << " is made.\n";
    }
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureacurat " << GREEN << _name_ << RESET" destroyed.\n";
}

Bureaucrat::Bureaucrat(Bureaucrat   const &src): _name_(src.getName())
{
    *this = src;
}

Bureaucrat  &Bureaucrat::operator=(Bureaucrat   const &src)
{
    _grade_ = src.getGrade();
    return(*this);
}

std::string Bureaucrat::getName() const
{
    return(_name_);
}

int Bureaucrat::getGrade() const
{
    return(_grade_);
}

void Bureaucrat::incrementGrade()
{
    try
    {
        if (_grade_ <= 1)
            throw   Bureaucrat::GradeTooHighException();
        else
            _grade_ -=1;
        std::cout << "Bureactrat " << GREEN << getName() << RESET" has been upgraded to grade " << getGrade() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << YELLOW"Exception thrown: " << RESET << e.what() << '\n';
    }   
}

void    Bureaucrat::decrementGrade()
{
    try
    {
        if (_grade_ >= 150)
            throw Bureaucrat::GradeTooLowException();
        else
            _grade_ +=1;
        std::cout << "Bureaucrat " << GREEN << getName() << RESET" has been downgraded to grade " << getGrade() << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << YELLOW"Exception thrown: " << RESET << e.what() << "\n";
    }
}


std::ostream     &operator<<(std::ostream &os,Bureaucrat const &src)
{
    return (os << YELLOW << src.getName() << ", bureaucrat grade " << src.getGrade() << RESET << "\n");
}
