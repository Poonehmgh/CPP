
#### pointer to class members

when a pointer to a class member is defined, you can only assign a value to it through a class instance.

```
#include <iostream>

class MyClass {
public:
    int x;
    void myFunction() {
        std::cout << "Hello from MyClass!" << std::endl;
    }
};

int main() {
    MyClass obj;
    MyClass* ptr = &obj;
    int MyClass::*ptrToMember = &MyClass::x;

    obj.*ptrToMember = 42;
    std::cout << "obj.x = " << obj.x << std::endl;

    ptr->*ptrToMember = 43;
    std::cout << "ptr->x = " << ptr->x << std::endl;

    void (MyClass::*ptrToFunction)() = &MyClass::myFunction;

    (obj.*ptrToFunction)();
    (ptr->*ptrToFunction)();

    return 0;
}

```

result:

[p](/Users/pooneh/Desktop/AR.png "AR.png")

![[Pasted image 20230508143459.png]]
![[Pasted image 20230508143527.png]]



#### Heap vs Stack

In C++, the stack and the heap are two regions of memory where data can be stored and accessed during the execution of a program.

-   The stack is a region of memory that is used to store local variables and function call data. When a function is called, a block of memory is reserved on the stack for the function's local variables and any temporary data that the function needs. When the function returns, this block of memory is freed and the stack pointer is adjusted accordingly.
-   The heap is a region of memory that is dynamically allocated at runtime and is not automatically deallocated when a function returns. Objects and data that are stored on the heap are usually accessed via pointers, and it is the responsibility of the programmer to deallocate the memory when it is no longer needed.

There are several key differences between the stack and the heap:

-   Lifetime: The lifetime of an object on the stack is limited to the duration of the function in which it is declared. Objects on the heap have a longer lifetime and are typically deallocated when they are no longer needed or when the program terminates.
    
-   Access: Objects on the stack are accessed directly, while objects on the heap are accessed through pointers.
    
-   Allocation: Memory on the stack is automatically allocated and deallocated by the system, while memory on the heap must be dynamically allocated and deallocated by the program.
    
-   Speed: Accessing and manipulating data on the stack is generally faster than accessing and manipulating data on the heap, because the stack is managed by the system and the memory is contiguous. The heap, on the other hand, is managed by the program and may contain fragments of unused memory.


Stack:

-   Stores data using a Last In First Out (LIFO) order
-   Managed by the compiler, automatically allocating and deallocating memory for variables
-   Limited in size, typically several megabytes
-   Faster memory access than heap due to its linear data structure
-   Memory allocation is performed at compile time

Heap:

-   Stores data using a dynamic memory allocation method
-   Managed by the programmer, allocating and deallocating memory using functions such as new and delete or malloc and free
-   Can be much larger than the stack, depending on the system resources
-   Memory access is slower than the stack due to its non-linear data structure
-   Memory allocated on the heap can be shared between functions
-   Memory allocation is performed at runtime

#### malloc in CPP

if you allocate memory in cpp for your class objects, it will be blown in your face. because the constructor would not be called in that case.


### what is a stream in CPP?

In C++, a stream is a **sequence of bytes that flow in or out of a program**. Streams can be used to read data from files or other input sources, or to write data to files or other output destinations. The standard library provides two types of streams: input streams and output.

Streams are typically associated with a specific source or destination, such as a file or a network socket. This association is established by creating an object of the appropriate stream class, such as `std::ifstream` for file input, or `std::ofstream` for file output. Once the stream is associated with the source or destination, data can be read from or written to the stream using standard input/output operations.

#### C01 

##### ex01

- newZombie: since we want to access it from outside world, it should be a pointer and memory should be allocated via `new`.
otherwise it will disappear after being called and you cannot use it through other functions.
when I try to return address of a local variable, this error happens: 

![[Pasted image 20230508153910.png]]
This error message indicates that you are returning the address of a local variable that is allocated on the stack. When a function returns, all of its local variables are destroyed, and their memory is freed. If you return a pointer to a local variable, the pointer will become invalid as soon as the function returns, and attempting to use it will result in undefined behavior.

in C, we could compile our program returning an address of our local variable, but in CPP we cant. (with warning though)

##### ex02

allocation of array of Zombies all at once: 
![[Pasted image 20230508163253.png]]

freeing: the [] make sure the entire array is being freed up.
![[Pasted image 20230508163342.png]]

#### ex03
humanA: has a weapon and attacks with it. He gets his weapon in the constructor. 
humanB: has a weapon and attacks with it. He gets his weapon in the setWeapon() function. Because sometimes he is not armed. 
the main question here, is how to define the weapon attribute of each human, so that if you change their value, the human also have the updated weapon. 

if the weapon attribute of humanA is defined as a `weapon _weapon_` ,  in the below code:

```
Weapon club("crude spike");

HumanA bob("Bob", club);

bob.attack();

club.setType("other type");

bob.attack();
```

we would not be able to change the Weapon's value in HumanA class. 
because the value of weapon is handed as "crude spike" club, and then *a copy* of `club` is handed to HumanA. So when we change `club`, we don't change the Weapon value in HumanA.

if we do this:

```
bob._weapon.setType("other type");
```

we are directly changing HumanA's weapon, so it will change.


the solution for this, is to store the weapon in humanA as **Reference or pointer**: 

```
class HumanA

{
	
	public:
	
		HumanA(std::string name, Weapon &weap);
	
		Weapon get_weapon(void);
	
		void attack();
	
	private:
	
		Weapon &_weapon;
	
		std::string _name;

};
```

so `Weapon &_weapon_` means that the Weapon is stored as reference (along with its address), so if you point it to memory address of club, it will point to it when club's value changes, not only a copy of club anymore.

on the other hand, the HumanB should definitely get a pointer (cant have a reference). because it is sometimes not armed, and a reference cannot point to nothing. 

#### ex04
We need to open file and write on a file in this exercise. 

**Input/output file stream class**

```
#include<ifstream>
#include<sstream>
std::ifstream inputFile("name");
if (!inputFile.is_open())
	return (std::cerr<<"error in openning file.\n", 1);
  ```````````
  
  we need a stream buffer to read from file and write to it. 

```
std::stringstream buffer;
buffer << inputFile.rdbuf();
std::string contents = buffer.str();
```

##### Whats is a stringstream? 

`std::stringstream` is a class in C++ standard library that allows you to treat a string as a stream, just like the standard input/output streams `std::cin` and `std::cout`. It provides a way to read from or write to strings as if they were input/output streams.

It is useful when you need to manipulate strings as if they were input/output streams.

To use `std::stringstream`, we first create an instance of the class by including the `<sstream>` header file, then we can write data to it using the `<<` operator just like with `std::cout`, and read from it using the `>>` operator just like you would with `std::cin`. Once done manipulating the string, we can extract it using the `str()` member function.

##### Iterating over a string in C++

now that we have our content as a string, as have to iterate trough it. In C we used while and indexes, here we have more tools. the `find` member function of string class is the answer:


```
size_t pos = 0;
while ((pos = contents.find(s1, pos)) != std::string::npos) {
    ....;
    pos += s2.length();
}
````````

`contents.find(...)` is a function call to the `find()` member function of an `std::string` object called `contents`. The `find()` function searches the string for the first occurrence of a given substring, and returns the index of the first character of the substring if it is found, or `std::string::npos` if it is not found.

##### what was sed, anyway ?

"sed" is a Unix utility for parsing and transforming text files, and it is often used for advanced text editing and automation tasks. The phrase "Sed is for losers" is a reference to the notion that using "sed" to manipulate text is a less elegant solution than writing one's own code to perform the same task.

#### ex05

I really did not get this one first. but it is simpler than it looks. we literally have to print a message according to the input level. 

##### what are member function pointers and when do we use them?

Member function pointers can be useful in various scenarios, such as:

1.  Callback functions: When you want to register a member function of a class as a callback function to be called later by some external code.
    
2.  Generic programming: When you want to write generic code that can work with different classes and their member functions.
    
3.  Event-driven programming: When you want to handle events by calling member functions of a class.
    

In summary, member function pointers are a way to refer to a member function of a class without actually calling it, and can be useful in various scenarios, such as callback functions, generic programming, and event-driven programming.

Example:

```#include <iostream>

class MyClass {
public:
  void func1() { std::cout << "Hello from func1!" << std::endl; }
  void func2() { std::cout << "Hello from func2!" << std::endl; }
};

int main() {
  MyClass obj;
  
  // Declare a pointer to a member function of MyClass that takes no arguments and returns void
  void (MyClass::*ptr)();
  
  // Initialize the pointer to func1()
  ptr = &MyClass::func1;
  
  // Call the member function using the pointer
  (obj.*ptr)();
  
  // Reinitialize the pointer to func2()
  ptr = &MyClass::func2;
  
  // Call the member function using the pointer
  (obj.*ptr)();
  
  return 0;
}

```

what I learnt for declaring an array of function pointers: 

```
void (harl::*funcPtr[4])() = {&harl::_debug, &harl::_info, &harl::_warning, &harl::_error};
```

you need to declare with handle, because it can be any function if you don't provide the handle!

#### ex06

In `switch` if it is case 0 (I mean 0 is true) and we have no break, all of other cases would become valid. if we 
dont want switch to go from the point on, we have to break. so the exact value of X is equal to one of cases, from there on to 
end would be called. 
