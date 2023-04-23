#include"../inc/Animal.hpp"
#include"../inc/Cat.hpp"
#include"../inc/Dog.hpp"
#include"../inc/WrongAnimal.hpp"
#include"../inc/WrongCat.hpp"
#include <iostream>

int main (void) 
{

    /*       tests in the subject        */
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    std::cout << i->getType() << " " << std::endl;
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
    delete j;
    /*      tests for wrong animal class        */
    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongCat     *ii = new WrongCat();
    wrongMeta->makeSound();
    ii->makeSound();
    delete wrongMeta;
    delete ii;
    // /*      test for when we use equality operator on the class and subclass       */
    // Cat     kitty("Cat");
    // Animal  bird;
    
    // bird = kitty;
    // bird.makeSound(); //output: animal sound, not cat sound.
    // //this is not possible: kitty = bird;
    // /*      test for when allocate memory to different class types */

    // Animal *catt = new Cat("Cat");
    // catt->makeSound(); // meaow --> although it is animal, the sound is cat sound bcz it is dynamic polymorphism. 

    // /*      general test    */
    // Cat cat("Cat");
    // Dog dog("Dog");
    // cat.makeSound();
    // dog.makeSound();
}