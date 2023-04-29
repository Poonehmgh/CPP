#ifndef AForm_H
# define AForm_H
# include <iostream>
# include <exception>
#include "Bureaucrat.hpp"
# define  GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define MAGNETA "\033[1;35m"
# define  RESET "\e[0;37m"


class Bureaucrat;

class aForm
{
    public:
        aForm();
        aForm(std::string name, int execGrade, int signGrade);
        aForm(aForm const &src);
        virtual ~aForm();
        class GradeTooHighException: public std::exception
        {
            virtual const char *what() const throw()
            {
                return("the grade is too high. max grade: 1\n");
            }
        };
        class GradeTooLowException: public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("the grade is too low. min grade: 150\n");
            }
        };
        class FormNotSignedException: public std::exception
        {
            virtual const char *what() const throw()
            {
                return("the form is not signed and cannot be executed.\n");
            }
        };
        aForm           &operator=(aForm const &src);
        std::string     getName() const;
        bool            getSignBool() const;
        int             getSignGrade() const;
        int             getExecGrade() const;
        void            beSigned(Bureaucrat *person);
        virtual void    execute(Bureaucrat const &executor) const = 0;
    private:
        std::string     _name_;
        bool            _signed_;
        int             _signGrade_;
        int             _executeGrade_;
};

std::ostream    &operator<<(std::ostream &os, aForm const &src);

#endif