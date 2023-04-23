# ifndef WRONGCAT_H
# define WRONGCAT_H

#include "../inc/Animal.hpp"

class WrongCat: public Animal
{
    public:
    WrongCat();
    WrongCat(std::string type);
    ~WrongCat();
    WrongCat(WrongCat const &src);
    WrongCat &operator=(WrongCat const &src);
    void makeSound() const;
};

#endif