#include"../inc/Animal.hpp"
#include"../inc/Cat.hpp"
#include"../inc/Dog.hpp"
#include"../inc/WrongAnimal.hpp"
#include"../inc/WrongCat.hpp"
#include <iostream>

int main (void) 
{

    /*       tests in the subject        */
    {
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
    }
    /*      tests for wrong animal class        */
    {
        const WrongAnimal *wrongMeta = new WrongAnimal();
        const WrongCat     *ii = new WrongCat();
        wrongMeta->makeSound();
        ii->makeSound();
        delete wrongMeta;
        delete ii;
    }
    /*      test for when we use equality operator on the class and subclass       */
    {
        Cat     kitty("Cat");
        Animal  animal_one;
        
        animal_one = kitty;
        animal_one.makeSound(); //output: animal sound, not cat sound.
    //this is not possible: kitty = animal_one;
    }
    /*      test for when allocate memory to different class types */
    {
        Animal *catt = new Cat("Cat");
        catt->makeSound(); // meaow --> although it is animal, the sound is cat sound bcz it is dynamic polymorphism. 
    }
    /*      general test    */
    {
        Cat cat("Cat");
        Dog dog("Dog");
        cat.makeSound();
        dog.makeSound();
    }
    /*      test to see what happens when the makeSound function is not virtual in wrongAnimal  */
    {
        WrongAnimal *animal_two = new WrongCat("cat");
        animal_two->makeSound(); // WRONG ANIMAL'S NOISES --> although it is allocated dynamically, since it is not a virtual function, it is not polymorphic.
        // so we wont see meaw.
        WrongCat    kitty("Cat");
        WrongAnimal animal_three;
        animal_three = kitty;
        animal_three.makeSound(); //  WRONG ANIMAL'S NOISES as we expected, animal sound, not cat sound.
    }
}