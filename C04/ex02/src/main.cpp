#include"../inc/Cat.hpp"
#include"../inc/Dog.hpp"
#include"../inc/Brain.hpp"
#include"../inc/aAnimal.hpp"
#include <iostream>

int main (void) 
{
    Cat cat("Cat");
    Dog dog("Dog");
    cat.makeSound();
    dog.makeSound();
    //cant define: aAnimal x     bcz it is abstract class. only being used by the sub classes.
    /*  test for deep copy of brain */
    cat.think("I love summer.");
    cat.think("I hate winter.");
    Cat other_cat(cat);
    other_cat.sayThoughts(0);
    cat.~Cat();
    other_cat.sayThoughts(0);
}