#include"../inc/Animal.hpp"
#include"../inc/Cat.hpp"
#include"../inc/Dog.hpp"
#include"../inc/Brain.hpp"
#include <iostream>

int main (void) 
{
    {
        /*              test the basic implementation of brain      */
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
    }
    // {
    //     /*          test for deep copiy of copy operator        */
    //     Dog braian("Dog");
    //     braian.think("I am pretty.");
    //     Dog copyBraian = braian;
    //     braian.~Dog();
    //     copyBraian.makeSound();
    //     copyBraian.sayThoughts(0);
    // }
    // {
    //     /*          test for deep copiy of copy constructor        */
    //     Dog braian("Dog");
    //     braian.think("I am pretty.");
    //     Dog copyBraian(braian);
    //     braian.~Dog();
    //     copyBraian.makeSound();
    //     copyBraian.sayThoughts(0);
    // }
   
//    {
//         /*          array of Animal obj         */
//         Animal *array[10];
//         for (int i  = 0; i < 10; i++)
//         {
//             if (i < 5)
//                 array[i] = new Dog();
//             else
//                 array[i] = new Cat();
//         }
//         for (int i = 0; i < 10; i++)
//         {
//             array[i]->makeSound();
//             delete array[i];
//         }
//     }
    {
        /*          extra tests for leak        */
        // const Animal* j = new Dog();
        // const Animal* i = new Cat();
        // delete j;//should not create a leak
        // delete i;
    }
    // /*      if the destructor is not virtual    */
    // {
    //     Animal *animal_four = new Cat("cat");
    //     delete animal_four; //this will give error, because the destructor wont be called and the dealocations wouldnt be done.
    //     // but when both are virtual, it ensures that both the base class destructor and the 
    //     // derived class destructor are called when deleting an object through a base class pointer.
    // }
}