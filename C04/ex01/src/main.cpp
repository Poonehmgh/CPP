#include"../inc/Animal.hpp"
#include"../inc/Cat.hpp"
#include"../inc/Dog.hpp"
#include"../inc/Brain.hpp"
#include <iostream>

int main (void) 
{
    /*              test the basic implementation of brain      */
    // Dog brian("Dog");
    // brian.think("I am feeling hungry!");
    // brian.think("I should ask hooman to give me some biffi!");
    // brian.makeSound();
    // brian.think("He doesnt hear me?!");
    // brian.think("I'll go get it myself.");
    // for (int i = 0; i < 4; i++)
    //     brian.sayThoughts(i);
    // for (int i = 4; i < 100; i++)
    //     brian.think("I am cyborg.\n");
    // brian.sayThoughts(98);
    // brian.sayThoughts(110);
    // brian.sayThoughts(0);
    /*          test for deep copies        */
    // Dog braian("Dog");
    // braian.think("I am pretty.");
    // Dog copyBraian = braian;
    // braian.~Dog();
    // copyBraian.makeSound();
    // copyBraian.sayThoughts(0);
    /*          array of Animal obj         */
    Animal *array[10];
    for (int i  = 0; i < 10; i++)
    {
        if (i < 5)
            array[i] = new Dog();
        else
            array[i] = new Cat();
    }
    for (int i = 0; i < 10; i++)
    {
        array[i]->makeSound();
        delete array[i];
    }
}