# ifndef DOG_H
# define DOG_H

#include "../inc/aAnimal.hpp"
#include "../inc/Brain.hpp"

class Dog: public aAnimal
{
    public:
    Dog();
    Dog(std::string type);
    ~Dog();
    Dog(Dog const &src);
    Dog &operator=(Dog const &src);
    void makeSound() const;
    void think(std::string idea);
    void sayThoughts(int i);
    private:
    Brain   *_myBrain_;
};

#endif