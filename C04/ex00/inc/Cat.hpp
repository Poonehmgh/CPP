# ifndef CAT_H
# define CAT_H

#include "../inc/Animal.hpp"

class Cat: public Animal
{
    public:
    Cat();
    Cat(std::string type);
    ~Cat();
    Cat(Cat const &src);
    Cat &operator=(Cat const &src);
    void makeSound() const;
};

#endif