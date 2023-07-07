#ifndef SHRUBBYCREATIONFORM_H
# define SHRUBBYCREATIONFORM_H

# include "aForm.hpp"
class aForm;

class ShrubbyCreationForm: public aForm
{
    public:
        ShrubbyCreationForm();
        ShrubbyCreationForm(std::string target);
        ShrubbyCreationForm(ShrubbyCreationForm const &src);
        ~ShrubbyCreationForm();
        ShrubbyCreationForm &operator=(ShrubbyCreationForm  const &src);
        void    execute(Bureaucrat  const &executor) const;
        void    executeForm(void) const;
        std::string getTarget() const;
    private:
        std::string _target_;
};

#endif