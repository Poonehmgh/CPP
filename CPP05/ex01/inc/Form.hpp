#ifndef FORM_H
# define FORM_H
# include <iostream>
# include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(std::string name, int execGrade, int signGrade);
        Form(Form const &src);
        ~Form();
        class GradeTooHighException: public std::exception
        {
            virtual const char *what() const throw()
            {
                return("the grade is too high.\n");
            }
        };
        class GradeTooLowException: public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("the grade is too low.\n");
            }
        };
        Form            &operator=(Form const &src);
        std::string     getName() const;
        bool            getSignBool() const;
        int             getSignGrade() const;
        int             getExecGrade() const;
        void            beSigned(Bureaucrat *person);
    private:
        const std::string   _name_;
        bool                _signed_;
        const int           _signGrade_;
        const int           _executeGrade_;
};

std::ostream    &operator<<(std::ostream &os, Form const &src);

#endif