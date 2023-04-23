# ifndef DOG_H
# define DOG_H

#include "../inc/Animal.hpp"

class Dog: public Animal
{
    public:
    Dog();
    Dog(std::string type);
    ~Dog();
    Dog(Dog const &src);
    Dog &operator=(Dog const &src);
    void makeSound() const;
};

#endif