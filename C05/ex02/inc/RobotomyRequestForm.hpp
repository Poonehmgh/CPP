#ifndef RobotomyRequestForm_H
# define RobotomyRequestForm_H

# include "aForm.hpp"
class aForm;

class RobotomyRequestForm: public aForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &src);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(RobotomyRequestForm  const &src);
        void    execute(Bureaucrat  const &executor) const;
        void    executeForm(void) const;
        std::string getTarget() const;
        class BadLuck: public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("You weren't lucky. ");
            }

        };
    private:
        std::string _target_;
};

#endif