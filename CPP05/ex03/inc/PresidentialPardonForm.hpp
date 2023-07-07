#ifndef PresidentialPardonForm_H
# define PresidentialPardonForm_H

# include "aForm.hpp"
class aForm;

class PresidentialPardonForm: public aForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(PresidentialPardonForm  const &src);
        void    execute(Bureaucrat  const &executor) const;
        void    executeForm(void) const;
        std::string getTarget() const;
    private:
        std::string _target_;
};

#endif