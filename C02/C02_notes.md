##### canonical form

it needs 4 below: 
	- constructor
	- destructor
	- copy constructor
	- copy assignment operator

###### copy constructor: 

This constructor takes an instance of the same class as an argument and creates a new instance with the same values for its member variables.

The copy constructor is used to create a new object as a copy of an existing object. It is typically used when you want to make a deep copy of an object, which means that the new object has its own copy of all the data members of the original object.

There are several situations where you may need to use a copy constructor, such as:

1.  When you want to pass an object to a function by value: If you pass an object by value, a copy of the object is created. The copy constructor is used to create this copy.
    
2.  When you return an object from a function by value: Similar to passing an object by value, a copy of the object is created when you return it from a function. Again, the copy constructor is used to create this copy.
    
3.  When you initialize an object using another object: If you initialize an object using another object of the same type, the copy constructor is called to create the new object.
    
4.  When you create a new object as a copy of an existing object: This is the most common use case for the copy constructor. You create a new object that is an exact copy of an existing object.
    

In general, any time you need to create a new object that is a copy of an existing object, you will need to use the copy constructor

##### copy assignment operator (equality operator)

![[Pasted image 20230415134533.png]]

When implementing a copy assignment operator, the decision to perform a shallow copy or a deep copy depends on the ownership and semantics of the data in our class. Here's a general guideline:

1.  Shallow Copy: Use a shallow copy **when your class does not own any dynamically allocated resources** and can safely share the same underlying data between multiple instances. In this case, simply copying the pointers or references to the data members is sufficient. Shallow copying is generally more efficient as it avoids duplicating data.

    
2.  Deep Copy: Use a deep copy **when your class owns dynamically allocated resources** (such as memory, file handles, ...) or when it contains complex objects that require independent copies. Deep copying involves creating new copies of the underlying data, ensuring that each instance manages its own separate resources. Deep copying is necessary to avoid issues with resource ownership and to provide independent state for each object.
3. 
#### Instructions for copy assignment operator

1.  Check for self-assignment: Before performing any copy operations, check if the source object and the destination object are the same. If they are the same, simply return the current object without doing any work.

Checking for self-assignment is a common practice in copy assignment operators to handle the case where the source object and the destination object are the same.

In the self-assignment scenario, if you don't check for self-assignment, the copy assignment operator could mistakenly deallocate or modify the resources of the object itself, leading to undefined behavior and potential crashes.

By checking for self-assignment, you can avoid unnecessary work and ensure the copy assignment operator handles the self-assignment case correctly. If the objects are the same (i.e., the source object's address is the same as the destination object's address), you can simply return the current object without performing any copy operations. This helps maintain the integrity of the object and prevents potential issues.

![[Pasted image 20230501163537.png]]

2.  Allocate new resources (if necessary): If your class manages any dynamically allocated resources, you may need to **deallocate the existing one** in the destination object and allocate new resources based on the source object. 

3.  Copy the data: Copy the data from the source object to the destination object. This may involve copying individual members or calling the copy assignment operator of any member objects.

4.  Return a reference to the destination object: The copy assignment operator should return a reference to the destination object to support chaining assignments.

#### Example for both cases:
![[Pasted image 20230501163717.png]]
![[Pasted image 20230501163739.png]]
ex00
##### returning by value vs returning by reference
###### an example, my mistake: 
in this excersice, if I define my copy constructor as below, I would encounter an stack overflow. why? 
```
Fixed Fixed::operator=(Fixed const &src) 
{
	std::cout<<"Copy assignment operator called.\n"; 
	_fixPoint_ = src.getRawBits(); 
	return *this; 
}
```

The reason for the stack overflow error in this code is that my *copy assignment operator* is defined to return a `Fixed` object by **value**. When a function returns a value by value, **the compiler creates a temporary object of the same type and copies the returned value to this temporary object.

In this code, the copy assignment operator takes a `Fixed` object by const reference as an argument, assigns its value to the `_fixPoint_` data member, and returns the `Fixed` object by value. However, since the return value is a new object, the copy constructor is called to create a temporary `Fixed` object, which is then used to initialize the return value.

But the copy constructor is defined as a member function that takes a `Fixed` object by const reference, and it calls the *copy assignment operator* to perform the assignment. So when the copy constructor is called, it calls the copy assignment operator, which returns a new object and triggers the copy constructor again, and so on. This creates an infinite loop of calls to the copy constructor and copy assignment operator, which eventually causes a stack overflow error due to the excessive recursion.

**The problem here is that the `operator=` function returns a new object by value, which causes the copy constructor to be called repeatedly, leading to an infinite recursion. To fix this issue, you should return a reference to the object being assigned, instead of creating a new object and returning it by value.**

###### returning value by reference:
Returning a reference means that the function returns a reference to the **same object that was passed in**. In terms of memory, returning a reference may be slightly more efficient, as it avoids creating a new object.

if I want to have a value returned by value (meaning that a copy of main value would be returned) then I should do this: 

```
Fixed Fixed::operator=(Fixed const &src) 
{
	std::cout<<"Copy assignment operator called.\n"; 
	Fixed ret; 
	ret._fixPoint_ = src.getRawBits(); 
	return ret; 
}
```

conclusion: whenever returning by value, a copy will be returned. whenever returning by refrence, the same instance would be returned. 

#### float numbers
- Floating point representations vary from machine to machine
- most common these days: the IEEE-754 standard
- An IEEE-754 float (4 bytes) or double (8 bytes) has three components 
	- The sign bit determines whether the number is positive or negative.
	-   The exponent represents the power of two by which the fraction is multiplied to get the actual value of the number.
	-   The fraction represents the fractional part of the number in binary format.


##### Fixed point number 
Fixed-point numbers are a type of numeric data representation used in computer programming and digital signal processing. **Unlike floating-point numbers, which have a varying number of digits to represent the fractional part of a number, fixed-point numbers use a fixed number of bits to represent both the integer and fractional parts of a number.**

In fixed-point notation, the bits that represent the integer part of a number are located to the left of a fixed point (=bit point), and the bits that represent the fractional part are located to the right of the fixed point. The fixed point is typically placed at a specific location in the number format, such as after a certain number of bits.

Fixed-point notation is often used in embedded systems and other specialized applications where the hardware or software is not powerful enough to handle floating-point arithmetic efficiently. Fixed-point arithmetic is typically faster and more efficient than floating-point arithmetic on such systems, although it can be less precise.

Fixed-point numbers can be represented using a variety of formats, including signed or unsigned, with different sizes for the integer and fractional parts. The number of bits used to represent the fractional part is typically fixed and known as the "number of fractional bits" or "precision."

![[Pasted image 20230411153227.png]]
we can represent negative number in fixed point: Use 2's complement.
-fixed point numbers are indeed a close relative to integer representation. The two only differs in the position of binary point.

###### an Example 
The fixed-point representation of 3.25 depends on the number of fractional bits used. For example, if we use 8 fractional bits, we can represent 3.25 as:

3.25 * 2^8 = 832

So, in this case, the fixed-point representation of 3.25 would be 832. Note that if we want to convert this fixed-point representation back to a floating-point value, we can simply divide by 2^8:

832 / 2^8 = 3.25 (in decimal)

So, the original floating-point value can be recovered without loss of precision.

So, what are we exactly doing when using the fixed point representation? We have a float, we declare a fractional bit amount, and we multiply it to a certain number, now we only have an int which we can simply show it via our bits. Whenever we want, we can turn the number to its original mode. 


##### dummy variable

The `operator++(int)` is a post-increment operator overload for the `Fixed` class. The `int` in the parentheses is a dummy integer parameter that is used to differentiate the post-increment operator overload from the pre-increment operator overload (`operator++()`).

In C++, you can define a function parameter without providing a name for it. This is commonly used when the function doesn't actually use the parameter and it is only included to satisfy a requirement, such as in the case of the post-increment operator overload.

##### storage classes 
..
##### ex02
in implementing the operations, the question is, that when we should deal with fixedpoint values and when we convert it to float and deal with the float version of the number?
for example, when we do a++, we proceed the operation on the fixed point value of a? or on the float version? 

- When performing arithmetic operations on fixed-point numbers, it's generally more convenient to convert them to floating-point numbers first, perform the operation, and then convert back to fixed-point format. so in these cases, we need to do do the operation on the float equivalent number, and then convert it back to fixed. 
this code: 
```
Fixed Fixed::operator+(Fixed const &src)

{

float tmp;

tmp = this->toFloat() + src.toFloat();

this->_fixPoint_ = roundf(tmp * (1 <<_numFracBits_));

return (tmp);

}
```

is calculating correctly, first converts to floats and then does the arithmetic operation and then converts back to fixed point. it doesnt return a copy though, so the value of called instance would be changed after this operation. this is not cool, because that is not the case all the time. sometimes we just want to add (or other operators) two instances to put the result in another instance, and we dont wanna our original instance to chane. so this is better code that does same calculation:

```
Fixed Fixed::operator+(Fixed const &src)

{

Fixed tmp (this->toFloat() + src.toFloat());

return (tmp);

}
```

- what about pre and post increment/decrement operators? 

For the increment and decrement operators (`++`, `--`), we need to implement both pre- and post-increment and decrement operators to increase or decrease the raw bits of the `Fixed` object by **the smallest representable epsilon.** which means: operation should be done on the rawbits.

- what about min/max ? 
  
For the `min` static member function, we should compare the float representations of the fixed-point numbers. This is because the smallest fixed-point number in terms of its float representation may not be the smallest in terms of its raw bits.
