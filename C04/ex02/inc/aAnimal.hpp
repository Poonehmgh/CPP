#ifndef aAnimal_H
# define aAnimal_H
#include<iostream>

# define BLUE "\033[0;34m"
# define RED "\033[0;31m"
# define RESET "\033[0m"

class aAnimal
{
    public:
        aAnimal();
        virtual ~aAnimal();
        aAnimal(aAnimal const &src);
        aAnimal &operator=(aAnimal const &src);
        void setType(std::string type);
        std::string getType(void) const;
        virtual void    makeSound() const = 0;
    protected:
        std::string _type_;
};

#endif