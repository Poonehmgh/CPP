#ifndef ANIMAL_H
# define ANIMAL_H
#include<iostream>

# define BLUE "\033[0;34m"
# define RED "\033[0;31m"
# define RESET "\033[0m"
class Animal
{
    public:
    Animal();
    virtual ~Animal();
    Animal(Animal const &src);
    Animal &operator=(Animal const &src);
    void setType(std::string type);
    std::string getType(void) const;
    virtual void    makeSound() const;
    protected:
    std::string _type_;
};

#endif