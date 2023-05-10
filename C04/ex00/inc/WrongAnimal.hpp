#ifndef WrongAnimal_H
# define WrongAnimal_H
#include<iostream>

# define BLUE "\033[0;34m"
# define RED "\033[0;31m"
# define RESET "\033[0m"
class WrongAnimal
{
    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(WrongAnimal const &src);
        WrongAnimal &operator=(WrongAnimal const &src);
        void setType(std::string type);
        std::string getType(void) const;
        void    makeSound() const;
    protected:
        std::string _type_;
};

#endif