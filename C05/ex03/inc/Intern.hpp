#ifndef Intern_H
# define Intern_H

# include "aForm.hpp"
class aForm;

class Intern
{
    public:
        Intern();
        Intern(Intern const &src);
        ~Intern();
        Intern &operator=(Intern  const &src);
        std::string getTarget() const;
        std::string getFormName() const;
        aForm   *makeForm(std::string name, std::string target);
    private:
        std::string _target_;
        std::string _name_;

};

#endif