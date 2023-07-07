### C04

###### ex00
##### polymorphism

Polymorphism in C++ means, the same entity (function or object) behaves differently in different scenarios.

Its a concept in object-oriented programming that allows objects of different types to be treated as if they were objects of the same type. It allows a subclass to inherit the methods and attributes of a superclass and also to override or extend those methods to provide specific behavior.

There are two main types of polymorphism:
    
1.  Compile-time polymorphism, also known as **static polymorphism**, which occurs during the compilation of the program. It is achieved through function overloading and templates.
2.  Runtime polymorphism, also known as **dynamic polymorphism** or **sub-type polymorphism**, which occurs during program execution. It is achieved through function overloading, function overriding, and virtual functions.

Compile-time polymorphism or **parametric polymorphism** is determined at compile time and is achieved using **function overloading and operator overloading.** 
In function overloading, multiple functions with the same name but different parameters are defined, and the appropriate function is selected based on the number, types, and order of the arguments passed.
In operator overloading, the behavior of an operator is defined for user-defined types like the operator "=" that we use in canonical form for exmaple. 

```#include <iostream>
using namespace std;

void print(int num) {
    cout << "Printing integer: " << num << endl;
}

void print(float num) {
    cout << "Printing float: " << num << endl;
}

int main() {
    int a = 5;
    float b = 5.5;

    print(a);  // Calls the print() function that takes an int argument
    print(b);  // Calls the print() function that takes a float argument

    return 0;
}

```



Run-time polymorphism, on the other hand, is determined at run time and is achieved using **functions overriding and virtual functions**. 
In function overriding, we give the new definition to base class function in the derived class. At that time, we can say the base function has been overridden. It can be only possible in the ‘derived class’. In function overriding, we have two definitions of the same function, one in the superclass and one in the derived class. The decision about which function definition requires calling happens at **runtime**. That is the reason we call it ‘Runtime polymorphism


Inheritance allows a derived class to inherit properties and behavior from a base class, and enables run-time polymorphism through virtual functions:
![[Pasted image 20230423102145.png]]

```
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "This is an animal." << endl;
    }
};
// The virtual keyword here created a V-Table which contains a list of all 
// virtual functions of our base class to be able to map them to the overwritten 
// functions of the derived classes at RUNTIME.

class Dog : public Animal {
public:
    void speak() {
        cout << "This is a dog." << endl;
    }
};

class Cat : public Animal {
public:
    void speak() {
        cout << "This is a cat." << endl;
    }
};

int main() {
    Animal* ptr;
    Dog dog;
    Cat cat;

    ptr = &dog;
    ptr->speak();  // Calls the Dog class's speak() function

    ptr = &cat;
    ptr->speak();  // Calls the Cat class's speak() function

    return 0;
}

or :

int main()
{
	Animal *catty = new cat();
	Animal *doggy = new dog();

	catty->speak();
	doggy->speak();
}
```


In virtual functions, a function in a base class is marked as "virtual", and **the behavior of the function is determined at run time based on the actual type of the object**, rather than the static type. This allows for overriding of the function in derived classes. 
When we declare a virtual function, the compiler determines which function to invoke at runtime.


##### virtual destructor

The problem with this instantiation is that we assign a cat class object to an Animal class object
and when we want to delete that memory (catty is alloced on the heap), we'll pass an Animal class object (i.e. catty) to the delete function. This makes the default destructor of the Animal class to run, not freeing all the memory allocated in the cat class. (so the destructor of cat is not called, which may lead to unfreed memory.) 
To solve this, we make the destructor of Animal class a virtual destructor. This way, the compiler knows not to use the default destructor of class Animal. but instead to use the cat destructor first.
So, when we are attempting to `delete` an object of a class that has virtual functions but a non-virtual destructor, we will delete an object through a pointer to its base class (in this case, `Animal`). Then since the base class destructor is not virtual, the derived class destructor will not be called, which could result in memory leaks or other undefined behavior.

**When a destructor is declared virtual in a class, it means that the destructor will be called in the reverse order of the constructor calls when an object of that class is destroyed. This is important when we have a class hierarchy with inheritance and polymorphism.**

##### ex01
##### Dynamic cast & inheritance

in this code, dog is a subclass of Animal, but I cannot access its non-animal functions: 

```
int main (void)

{
	Animal *brian= new Dog("Dog");
	brian->makeSound(); // animal function is reachable. 
	brian->think("I am thursty.");  // non-animal function is not reachable.
}
```

Since the pointer `brian` is of type `Animal*`, which is a base class pointer, I can only access the members of `Animal` through it. So I cannot directly call `Dog::think()` using `brian`.

One solution to access `Dog::think()` through `brian` is to use a `dynamic_cast`. The `dynamic_cast` operator allows one to convert a pointer/reference of base class type to a derived class type if the object being pointed to is actually of the derived class type. 
example of `dynamic_cast` to access `Dog::think()` through `brian`:

```
Animal  *brian= new Dog("Dog");
brian->makeSound();

// Try to cast the pointer to Dog*
Dog *myDog = dynamic_cast<Dog*>(brian);

// Check if the cast was successful
if (myDog != nullptr)
{
    myDog->think("I am thirsty.");
    myDog->test();
}

```

##### copy constructor for copying brain

```
Cat::Cat(Cat const &src)

{

	*this = src;
	
	this->_myBrain_ = new Brain;
	
	*_myBrain_ = *src._myBrain_;
	
	std::cout << "Cat copy constructor is called.\n";

}
```

but the equal operator is:

```
Cat &Cat::operator=(Cat const &src)

{
	this->setType(src.getType());
		
	std::cout << "Cat copy operator called.\n";
	
	this->_myBrain_ = src._myBrain_;
	
	return(*this);

}
```

Why here, we dont allocate a new memory for brain, but in the copy constructor we do? 


![[Pasted image 20230423170331.png]]
another question, why in the copy constructor we make a `*this = rhs` sometimes, and sometimes we copy item by item? isnt it like C, that the pointer points to the whole of rhs? so we dont need to do copy item by item?
and what is the diff btw copy constructor and = operator ?

##### shallow copy vs deep copy

when an object is copied, a copy constructor is called. Depending on the implementation of the copy constructor, the new object can be a shallow copy or a deep copy of the original object.

A shallow copy copies the values of the member variables of an object to another object *without creating new copies of the objects pointed to by the member variables*. This means that **the copied object and the original object share the same memory addresses** for the objects pointed to by the member variables. So, if a change is made to the object pointed to by one copy, the other copy will be affected.

```
#include <iostream>
#include <cstring>

class ShallowCopy {
public:
    ShallowCopy(const char* str) {
        mSize = strlen(str);
        mData = new char[mSize];
        memcpy(mData, str, mSize);
    }

    ShallowCopy(const ShallowCopy& other) {
        mSize = other.mSize;
        mData = other.mData;
    }

    ~ShallowCopy() {
        delete[] mData;
    }

    void printData() {
        std::cout << mData << std::endl;
    }

private:
    char* mData;
    int mSize;
};

int main() {
    ShallowCopy a("Hello");
    ShallowCopy b = a;  // Shallow copy
    a.printData();      // Output: Hello
    b.printData();      // Output: Hello

    b.~ShallowCopy();   // Freeing b's memory
    a.printData();      // Error! a's mData is pointing to freed memory
}

```


On the other hand, a deep copy creates *a new copy of the objects pointed to by the member variables and copies the values to the new object.* This means that the copied object and the original object have their own copies of the objects pointed to by the member variables. So, if a change is made to the object pointed to by one copy, the other copy will not be affected.

It is important to note that whether a shallow copy or a deep copy is made depends on the implementation of the copy constructor. **If a class does not have a user-defined copy constructor, a default copy constructor is provided by the compiler. This default copy constructor makes a shallow copy of the object. Therefore, it is necessary to define a custom copy constructor to ensure that the correct type of copy is made.

```
#include <iostream>
#include <cstring>

class DeepCopy {
public:
    DeepCopy(const char* str) {
        mSize = strlen(str);
        mData = new char[mSize];
        memcpy(mData, str, mSize);
    }

    DeepCopy(const DeepCopy& other) {
        mSize = other.mSize;
        mData = new char[mSize];
        memcpy(mData, other.mData, mSize);
    }

    ~DeepCopy() {
        delete[] mData;
    }

    void printData() {
        std::cout << mData << std::endl;
    }

private:
    char* mData;
    int mSize;
};

int main() {
    DeepCopy a("Hello");
    DeepCopy b = a;  // Deep copy
    a.printData();   // Output: Hello
    b.printData();   // Output: Hello

    b.~DeepCopy();   // Freeing b's memory
    a.printData();   // Output: Hello
}

```

##### an example
this is a shallow copy:
```
this->setIdea(src.getIdea(i));
```
this is its deep copy:
```
_ideas_[i] = new std::string(*(src.getIdea(i)));
```

##### something to thing abt... 
this code:

![[Pasted image 20230423230821.png]]
![[Pasted image 20230423230800.png]]

and in main only: 

```
Dog braian("Dog");
Dog copyBraian = braian;
```

has this output:
![[Pasted image 20230423225935.png]]

##### analogy of the output: 
defining braian calls:
	animal constructor
	+ brain constructor
	+ dog constructor
defining copyBraian calls:
	dog copy operator -> calls animal copy constructor -> calls animal copy operator (equality)
		defining a new brain calls: 
			brain constructor
		brain copy operator -> brain copy constructor

then 
brain destructor
dog destructor
animal destructor
brain destructor
dog destructor
animal destructor

##### deep copy in this excersice 
 I made this main for the deep copy:  
 ![[Pasted image 20230423235748.png]]

since it is deep copied, the copyBraian's sayThoughts function should reflect the the thinking, although it is after braian's destructor call.
in the copy operator of brain, if I go as `this->setIdea(src.getIdea(i))`  it will segfault? No. 
but why? the memory of the _ideas_ is the same... :-? 

##### ex02
#### abstract class

In C++, an abstract class is a class that cannot be instantiated. An abstract class is designed to be used as a **base class** and is meant to be inherited by other classes. It usually has one or more **pure virtual functions** that are not defined in the abstract class, but must be defined in the derived classes. A pure virtual function is a function that has no implementation in the base class and is declared with the "virtual" keyword and "= 0".

To create an abstract class in C++, one need to define at least one pure virtual function in the class.

An abstract class provides a common interface for all the classes that inherit from it, and forces the derived classes to implement the pure virtual functions. This allows for a high degree of abstraction and polymorphism in the code. Abstract classes can be used to define interfaces, which is a way of specifying the behavior of a set of related objects without specifying their concrete implementation.

##### ex03

##### interface

an interface is defined as a class that consists only of pure virtual functions (i.e., functions that have no implementation). it is also called ure abstract classe.
Interfaces are commonly used to define a set of functions that must be implemented by multiple classes, providing a common interface for those classes. This allows for polymorphism and abstraction, as different concrete classes can implement the same interface in different ways, but can be used interchangeably in functions that take the interface as a parameter or return value.
Interfaces don’t exist in C++98 (not even in C++20). However, pure abstract classes are commonly called interfaces.

rules: 
-   Declare only pure virtual functions. (No definition)
-   For pure virtual functions assign only 0.
-   Cannot create an instance of the class.
-   We can create a pointer to the instance of the derived class with a reference of a base abstract class.

In C++, interfaces can only have public and protected member functions, but no data members. Therefore, interfaces cannot have private attributes.

##### ex04
#### materia 
if you are like me, a non gamer, this is materia! a sort of weapon in final fantasy. 
![[Pasted image 20230424185748.png]]

#### what is this exercise about? 

Here, we are making a game that has Characters and Materia for Characters to do stuff with.
Materias are stored in a place named MateriaSource, and when we make a MateriaSource, we can add different Materias to it. (its storage capacity for Materias is 4).

iCharacter is a character interface, it acts like Character template. so you can build your characters based on this, and make sure that it has certain features. Thats why we use interface here. In this exercise, we only have one subclass of character interface (iCharacter). 

```

iCharacter *jo = new Character("jo");

```

Polymorphism at run time --> iCharacter is built, and at run time, it is understood that a Character child of iCharacter is meant to be used. 

iMateriaSource is a template for MateriaSource. 

```
iMateriaSource* src = new MateriaSource();
```

MateriaSource is the implementation of iMateriaSource interface, which means, it has to implement certain functions (it is oblifatory, again, the point of having an interface).
The obligatory functions are:
- learnMateria: 
we say to the source which types of materia templates we have as template. we give it the materia and it stores it as template in the inventory.
- createMateria:
we create a new materia with this, a clone of the materia addressed from materia template (MateriaSource). 
and Materia itself, is an abstract class, because we do not need to instantiate it. we only want to use its subclasses: Ice & Cube.
Ice and Cube are the Materias as tools for the character. 
Characters equip themselves by taking materias from materiaSource and storing them in their inventory. 


![[Pasted image 20230426133558.png]]

##### some tests

```
/***test for MateriaSource ****/

{

iMateriaSource *src = new MateriaSource();

src->learnMateria(new Ice());

src->learnMateria(new Ice());

src->learnMateria(new Ice());

iCharacter *bob = new Character("bob");

aMateria *tmp = src->createMateria("cure"); //since we have no cube in materiasource, there should be no segfaults.

bob->equip(tmp);

/*** test for capacity of MateriaSource***/

src->learnMateria(new Cure());

src->learnMateria(new Cure());

tmp = src->createMateria("cure");

bob->equip(tmp);

delete src;

delete bob;

}

/*** test when there is no Materia created ***/

{

iMateriaSource *src = new MateriaSource();

src->createMateria("cure");

delete src;

}

/*** test for invalid index / invaluse use/equip input */

{

iMateriaSource *src = new MateriaSource();

src->learnMateria(new Cure());

src->createMateria("cure");

Character *me = new Character("me");

Character *you = new Character("you");

me->equip(src->createMateria("cure"));

aMateria *ptr = me->getInventory(0); //saving the Materia's address before unequiping

// me->use(2, *you); //invalid index because source is not full at this index

// me->use(10, *you); //invalid index

// me->use(0, *me); // can a character .use on themself?

me->unequip(0);

// me->use(0, *you); // check after unequiping.

me->equip(ptr); //reusing the address of dropped Materia;

me->use(0, *you);

delete me;

delete you;

delete src;

}
```

#### concrete classes
A concrete class in C++ is a class that provides implementation details for all its member functions, and can be instantiated. It is the opposite of an abstract class, which contains pure virtual functions and cannot be instantiated on its own.

A concrete class provides a complete implementation for all of its member functions, and therefore can be used directly by other classes or objects. It can be inherited by other classes, which can then use and possibly override the implementations of its member functions.

(When we say a concrete class implements all of its member functions, it means that all of the member functions declared in the class have a complete implementation or definition in the class. This is in contrast to abstract classes or interfaces, where some or all of the member functions may be declared without an implementation, leaving their implementation to the derived classes.)

In other words, a concrete class has a complete implementation of all of its member functions, and any derived classes can inherit these implementations and add new ones if necessary.

##### non def constructor for base class
so I encountered this in my code that if a parent class has no def const, and you wanna have a default constructor for the child class, you have to initialize the parent const otherwise it wont work!

##### Question: do I need to have canonical form for abstract and interface classes? 
interface: no , bcz thats the whole points of it, to provide you with the necessary functions to implement.
abstract: yes. 
##### Question: do I need to define the virtual fucntions in the abstract class? 
If you don't want to modify the declaration of `use` in the abstract class, you can leave it unimplemented in the `aMateria` class and let the subclass implement it. This is one of the main purposes of abstract classes: to provide a template for behavior that can be implemented differently by its subclasses.
