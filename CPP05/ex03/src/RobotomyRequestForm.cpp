# include"../inc/RobotomyRequestForm.hpp"
# include<fstream>
# include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : aForm("RobotomyRequestForm", 72, 45)
{
    _target_ = "default target";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : aForm("RobotomyRequestForm", 72, 45)
{
    _target_ = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << YELLOW << getName() << RESET" is torn apart.\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm    const &src): aForm(src.getName(), src.getSignGrade(), src.getExecGrade()) 
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
    _target_ = src.getTarget();
    return (*this);
}

void    RobotomyRequestForm::executeForm(void) const
{
    std::cout << "**** LOUD NOISE ****\n";
    std::cout << MAGNETA << getTarget() << RESET "has been robotomized.\n";
}

std::string RobotomyRequestForm::getTarget() const
{
    return(_target_);
}

void RobotomyRequestForm::execute(Bureaucrat  const &executor) const
{
    try
    {
        if (!this->getSignBool())
            throw(aForm::FormNotSignedException());
        else if (executor.getGrade() > this->getExecGrade())
            throw (aForm::GradeTooLowException());
        else if (rand() % 2)
            throw(RobotomyRequestForm::BadLuck());
        else
        {
            this->executeForm();
            std::cout << "Bureaucrat " << GREEN << executor.getGrade() << RESET" executed " << YELLOW << getName() << RESET"\n";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << MAGNETA"Exception thrown: " << e.what() << "Robotomy faild.\n" << RESET;
    }
}

