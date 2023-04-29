#ifndef bureaucrat_h
# define bureaucrat_h
# include<iostream>
# include <exception>
#include "aForm.hpp"
class aForm;
class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(Bureaucrat   const &src);
        Bureaucrat   &operator=(Bureaucrat   const &src);
        class GradeTooHighException: public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("the grade is too high. max grade: 1\n");
            }
        };
        class GradeTooLowException: public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("the grade is too low. min grade: 150\n");
            }
        };
        std::string getName() const;
        unsigned int getGrade() const;
        void    incrementGrade();
        void    decrementGrade();
        void    signForm(aForm *form);
        void    executeForm(aForm const &form);
    private:
        std::string          _name_; //check if it should be constant
        unsigned int                 _grade_;
};

std::ostream     &operator<<(std::ostream &os, Bureaucrat const &src);


#endif
