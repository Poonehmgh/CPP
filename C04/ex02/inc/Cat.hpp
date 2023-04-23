# ifndef CAT_H
# define CAT_H

#include "../inc/aAnimal.hpp"
#include "../inc/Brain.hpp"

class Cat: public aAnimal
{
    public:
    Cat();
    Cat(std::string type);
    ~Cat();
    Cat(Cat const &src);
    Cat &operator=(Cat const &src);
    void makeSound() const;
    void think(std::string idea);
    void sayThoughts(int i);
    private:
    Brain   *_myBrain_;
};

#endif