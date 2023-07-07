# ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
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