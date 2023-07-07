#### CPP cast

classes introduce a new hierarchy. parent is up and child is down

![[Pasted image 20230430113704.png]]


    implicit down cast:  no. compiler wouldnt let.
    explicit down cast: you can do, but not good.


##### static cast

![[Pasted image 20230430114317.png]]


class hierarchy:

![[Pasted image 20230430114600.png]]

to sum it up in CPP: 
	-implicit cast for promotion (upcast) : ok
	-explicit cast for promotion (upcast) : ok
	-implicit cast for demotion (downcast) : compiler error/ not ok
	-`<static_cast>` keywork (explicit cast) for downcast: ok
	- explicit cast (static keyword) for conversion between unrelated classes: compiler error. 


##### dynamic cast

the `dynamic_cast` operator is used for dynamic type casting between polymorphic types. It allows you to safely and efficiently cast pointers or references of base classes to pointers or references of derived classes at runtime. (**only used for down cast)

some features and rules of `dynamic_cast`:

1.  It is primarily used for casting within an inheritance hierarchy of classes, where the base class has at least one virtual function.
    
2.  It performs runtime type checking to ensure that the cast is valid. It allows you to check if a cast is successful by returning a pointer or reference of the target type if the cast is possible, or a **null pointer** if the cast fails.
    
3.  If the cast is from a pointer type to another pointer type, `dynamic_cast` requires the target type to be polymorphic, meaning it should have at least one virtual function.
    
4.  If the cast is from a reference type to another reference type, `dynamic_cast` does not require the target type to be polymorphic.
    
5.  If the cast is from a pointer type to a reference type or vice versa, the cast is not allowed using `dynamic_cast`.
    
6.  When casting from a base class pointer/reference to a derived class pointer/reference, `dynamic_cast` performs a runtime check to verify if the object being cast is actually of the target type or a type derived from it. If the cast is not valid, it returns a null pointer (for pointer cast) or throws a `std::bad_cast` exception (for reference cast).
7. only works with pointers or references.
8. casting is done in the run time. so the program may compile, but then the dynamic cast may fail at run time. so carefull to handle when the dyn cast fails.

it only works with polymorphic instances. subtyped pm, at least one of the member functs has to be virtual. 

##### Run-time type information (RTTI)
  
RTTI (Run-Time Type Information) is a feature in C++ that provides information about the type of an object at runtime. It enables dynamic type identification and dynamic casting of objects within an inheritance hierarchy.

The `dynamic_cast` operator relies on RTTI to perform type checking during the casting process. RTTI allows the `dynamic_cast` operator to determine whether the cast is valid and to handle the cast accordingly.

To enable RTTI, the class hierarchy must meet the following requirements:

1.  The base class must have at least one virtual function.
    
2.  The derived class must inherit publicly from the base class.
    
3.  The derived class must have at least one virtual function or derive from a class that has at least one virtual function.
    

When RTTI is enabled, the `dynamic_cast` operator can perform the following tasks:

1.  Determine if a cast from a base class pointer/reference to a derived class pointer/reference is valid.
    
2.  Perform downcasting (from a base class to a derived class) safely by checking the object's actual dynamic type at runtime.
    
3.  Return a null pointer when the cast is not valid (for pointer casting) or throw a `std::bad_cast` exception (for reference casting).

#### reinterpret cast

In C++, `reinterpret_cast` is a type of casting operator that allows you to reinterpret the bit pattern of an object or convert between unrelated types, as long as the requested conversion is possible in terms of the type system.

The `reinterpret_cast` operator is used to convert a pointer or reference of one type to a pointer or reference of another type, even if the types are unrelated. It performs a low-level reinterpretation of the bit pattern, allowing you to manipulate the memory representation directly.

![[Pasted image 20230430134847.png]]

It's important to note that `reinterpret_cast` is a powerful operator that should be used with caution. It bypasses the type system and allows you to reinterpret the underlying memory, which can lead to undefined behavior if misused. Therefore, it's crucial to ensure that the reinterpretation is well-defined and doesn't violate any language rules or assumptions.

Here's an example of using `reinterpret_cast`:

```
	int value = 42;
	float* floatValue = reinterpret_cast<float*>(&value); // Reinterpreting the int as a float

	unsigned int address = reinterpret_cast<unsigned int>(floatValue); // Reinterpreting the pointer as an unsigned int

```

##### const cast
allows to cast typequalifiers.

![[Pasted image 20230501134201.png]]

its not a good idea to const cast, it is dangerous to the data. 

#### cast operators

![[Pasted image 20230501134620.png]]

It allows you to define how an object of a class can be implicitly converted to another type. It is defined as a member function with the name `operator type()` where `type` represents the target type of the conversion. The conversion operator does not take any arguments and returns the converted value.

##### explicit keyword

The `explicit` keyword in C++ is used to declare constructors and conversion functions as explicit. It is used to prevent implicit conversions and enforce explicit conversions instead.

When a constructor or a conversion function is declared as explicit, it means that the compiler will not perform implicit conversions using that constructor or conversion function. Implicit conversions occur automatically when a value of one type is used in a context where another type is expected. By marking the constructor or conversion function as explicit, you require the use of an explicit cast or conversion syntax to perform the conversion.

```
class MyClass {
public:
  explicit MyClass(int value) : _value(value) {}
  int getValue() const { return _value; }
private:
  int _value;
};

int main() {
  MyClass obj1 = 42; // Error: Implicit conversion not allowed
  MyClass obj2(42); // OK: Explicit constructor call
  int value = obj2.getValue(); // OK: Accessing the value
  return 0;
}

```


![[Pasted image 20230501141816.png]]


ex00

#### static class? 

the subject asks us to write an static class. static class in CPP doesn't exist as I understood, and I found the subject file misleading. Nevertheless, according to the closest meaning to the static class, I understood that all functions be static in a class, then the class would be static. The problem is that with static class, we cannot instantiate any object, so the copy constructor and constructor and etc (canonical form) is not really meaning full. 
here, I made my class in a way, that only utility functions exist in it (so I got rid of the sub functions and attributes and etc which werent the final utility.) and the class could not use the constructor/destructor/=/copyconst by making them private. 

###### what should we do ?
we should static_cast, case by case, from a std::string input into char, int, double, etc
  
The statement "Except for char parameters, only the decimal notation will be used" means that for all scalar types (`int`, `float`, `double`), the string representation should be in decimal notation. This means that the numbers should be represented using the digits 0-9 and an optional sign (+/-) for negative numbers.

#### limits

```

float positiveInfinity = std::numeric_limits<float>::infinity();

```
and 

`std::numeric_limits<int>::min()` & `std::numeric_limits<int>::max()`

##### what to do with limits?

if we have "inff" or "-inf": I set its type to float. because I checked with cpp's own behavior and it is considered a float. I convert it to float like this: 

`float_ = static_cast<float>(atof(_string_.c_str()));`

atof is capable of taking care of it. the `atof` function converts the string "inff" to the floating-point value `inf`, which represents positive infinity.
then, I set my `int`, as invalid.

#### convert char * to std::string

To convert a `char*` to `std::string` in C++, you can simply pass the `char*` as an argument to the `std::string` constructor.

```
char* cString = "Hello, world!";
std::string str(cString);

```

to convert std::string to char *, `string.c_str()`  . 

##### one very important point in printing double and float

I understood that after the values are converted, the printed value of float and double was just like int, for example instead of `42.0` it was `42`. 
after some research, I understood that:

By default, when printing floating-point values using `std::cout`, the program will print only the necessary digits to represent the value accurately, without any trailing zeros. So, if a floating-point value has no fractional part or has only zeros after the decimal point, it will be printed without any decimal places.

So, If we want to control the precision and formatting of floating-point and double values, we can use the `<iomanip>` header, and `std::fixed` manipulator to set the precision to a fixed number of decimal places, and `std::setprecision` to specify the number of digits to display after the decimal point.
here my code is: 
```
std::cout << "float: " << std::fixed << std::setprecision(1) << src.float_ <<"f" << "\ndouble: " << std::fixed << std::setprecision(1) << src.double_ << "\n");
```

ex01

##### what is unintptr_t?

In C++, `uintptr_t` is an integer type defined in the `<cstdint>` header as part of the standard library. It is an optional type that is guaranteed to be an unsigned integer type with the same size as a pointer.

The `uintptr_t` type is used to hold an *unsigned integer value that can represent a pointer value* without loss of information. It is typically used in low-level programming or when dealing with pointer arithmetic or bitwise operations where you need to manipulate pointers as integers.

![[Pasted image 20230501144809.png]]

In this example, we use `uintptr_t` to store the value of a pointer `ptr` as an unsigned integer. We then use `reinterpret_cast` to convert the `uintptr_t` back to a pointer type `ptr2`. Finally, we compare the original pointer `ptr` with the converted pointer `ptr2` to check if they are equal.

#### why we are making the functions static? 

acc to subject file, we need to make the two mentioned functions of `serialize` and `deserialize` static functions. why we do that?

Making the `serialize` and `deserialize` functions static in the `Serializer` class allows us to **call these functions without needing an instance of the class.** When a member function is declared as static, it can be accessed directly using the class name, without the need to create an object of the class.
This can be convenient in scenarios where you only need to perform serialization or deserialization (or any other class method) and don't require the additional functionality or state of the object.

![[Pasted image 20230501161018.png]]

##### why we should use `reinterpret_cast`? 

`reinterpret_cast` is a powerful and that allows us to convert between **unrelated pointer types or between pointers and integers.**
Since the serialization process does not involve **polymorphic types** or **type conversions**, `reinterpret_cast` can be used to perform a direct and efficient conversion between the pointer and integer representation. Using `dynamic_cast` or `static_cast` would not be appropriate in this case, as they are designed for different purposes and would not provide the desired behavior:

![[Pasted image 20230501161756.png]]


ex02

#### rvalue & lvalue
the terms "rvalue" and "lvalue" refer to different categories of expressions.

An lvalue (short for "left value") refers to an **expression that identifies a specific object or memory location.** It represents an entity that has a name and can be assigned to or whose address can be taken. Examples of lvalues include variables, named constants, and non-static class members.

An rvalue (short for "right value") refers to an expression that **does not represent an object that is assignable or whose address can be taken.** It typically represents a temporary or intermediate value that is used in computations. Examples of rvalues include literal constants, temporary variables, and the results of expressions and function calls.

![[Pasted image 20230501175725.png]]

