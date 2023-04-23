#include"../inc/Animal.hpp"
#include"../inc/Cat.hpp"
#include"../inc/Dog.hpp"
#include"../inc/Brain.hpp"
#include <iostream>

int main (void) 
{
    Dog brian("Dog");
    brian.think("I am feeling hungry!");
    brian.think("I should ask hooman to give me some biffi!");
    brian.makeSound();
    brian.think("He doesnt hear me?!");
    brian.think("I'll go get it myself.");
    for (int i = 0; i < 4; i++)
        brian.sayThoughts(i);
    for (int i = 4; i < 100; i++)
        brian.think("I am cyborg.\n");
    brian.sayThoughts(98);
    brian.sayThoughts(110);
    brian.sayThoughts(0);
    // brian.think("I am thursty.\n");

    // Animal  *brian= new Dog("Dog");

    // brian->makeSound();
    // Dog *cast = dynamic_cast<Dog *>(brian);
    // cast->think("I am thursty.");

    // /*          array of Animal obj         */
    // Animal *array[10];
    // for (int i  = 0; i < 10; i++)
    // {
    //     if (i < 5)
    //         array[i] = new Dog();
    //     else
    //         array[i] = new Cat();
    // }
}