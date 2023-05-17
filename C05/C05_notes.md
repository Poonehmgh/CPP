### C05

#### nested classes

Nested classes, also known as nested types, are classes defined within another class. They are declared and defined inside the scope of the enclosing class and can have access to the private and protected members of the enclosing class. Nested classes can be useful for organizing and encapsulating related functionality within a class.
- Access to Enclosing Class: A nested class has access to all members (public, protected, and private) directly.
- Access to Nested Class: The enclosing class does not have direct access to the members of the nested class. If the nested class needs to be accessed from outside the enclosing class, it must be accessed using the scope resolution operator
- Visibility: The visibility of a nested class depends on its access specifier. By default, a nested class is considered to have the same access level as the enclosing class. If the nested class is declared as public, it can be accessed by code outside the enclosing class.

```
#include <iostream>

class OuterClass {
public:
    OuterClass() {
        std::cout << "OuterClass constructor called.\n";
    }

    void outerMethod() {
        std::cout << "Outer method called.\n";
        innerObj.innerMethod();
    }

    class InnerClass {
    public:
        InnerClass() {
            std::cout << "InnerClass constructor called.\n";
        }

        void innerMethod() {
            std::cout << "Inner method called.\n";
        }
    };

private:
    InnerClass innerObj;
};

int main() {
    OuterClass outerObj;
    outerObj.outerMethod();

    // Accessing the nested class from outside the enclosing class
    OuterClass::InnerClass innerObj;
    innerObj.innerMethod();

    return 0;
}

```

output: 

![[Pasted image 20230426201118.png]]

#### exceptions

In C++, exceptions are a mechanism for handling exceptional or error conditions that may occur during the execution of a program. They provide a way to transfer control from one part of the program to another, allowing you to handle errors gracefully and take appropriate actions.

Exceptions are raised when an exceptional situation occurs, and they can be caught and handled by appropriate exception handling code. When an exception is thrown, the normal flow of the program is interrupted, and the program looks for an exception handler that can handle the exception. If a matching handler is found, the control is transferred to the handler, allowing you to perform error handling or recovery operations.

1.  Exceptions are objects that are thrown and caught.
2.  Exceptions can be of any type, including built-in types, user-defined types, or standard library types.
3.  Exceptions can be thrown using the `throw` keyword and are caught using `try-catch` blocks. 
5.  Multiple `catch` blocks can be used to catch different types of exceptions. The catch blocks are evaluated in order, and the first matching catch block is executed.
6.  If an exception is not caught, it will propagate up the call stack until a matching catch block is found or the program terminates.
7.  **It is recommended to catch exceptions by reference to `const` to avoid unnecessary copying of exception objects.
8.  Standard library exceptions are provided by the `<stdexcept>` header, which includes common exception classes like `std::runtime_error`, `std::logic_error`, etc.
```
#include <iostream>

double divide(int dividend, int divisor) {
    if (divisor == 0) {
        throw "Divide by zero exception";
    }

    return static_cast<double>(dividend) / divisor;
}

int main() {
    int dividend, divisor;
    std::cout << "Enter dividend: ";
    std::cin >> dividend;
    std::cout << "Enter divisor: ";
    std::cin >> divisor;

    try {
        double result = divide(dividend, divisor);
        std::cout << "Result: " << result << std::endl;
    } catch (const char* errorMessage) {
        std::cout << "Exception caught: " << errorMessage << std::endl;
    }

    return 0;
}


```

1.  The user enters the dividend and divisor values.
2.  We call the `divide()` function within a `try` block.
3.  If the divisor is zero, the `divide()` function throws a string exception.
4.  The program jumps to the `catch` block, which expects a `const char*`.
5.  The error message is displayed.
6.  Program execution continues normally.


The `#include <exception>` , a preprocessor directive that includes the standard library header which provides a set of standard exception classes that are defined in the C++ Standard Library.

The `<stdexcept>` header defines several exception classes that can be used to handle common types of exceptions, such as `std::logic_error`, `std::runtime_error`, and `std::out_of_range`. These classes are derived from the base class `std::exception` and provide specific exception types for different error scenarios.

```
#include <stdexcept>
#include <iostream>

int main() {
    try {
        // Some code that may throw an exception
        throw std::runtime_error("Something went wrong!");
    } catch (const std::runtime_error& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }

    return 0;
}

```

In this example, we throw an `std::runtime_error` exception with a custom error message. The exception is caught in the `catch` block, and we use the `what()` member function to retrieve the error message and display it.

ex00
##### making an exception as a nested class

 we create a nested class, to inherit from base class Exception. Exception class has a member function `what()` that will be overwritten by the defined nested class's what function. 
 
```
class Bureaucrat{
	class GradeTooHighException : public std::exception 
	{
		virtual const char *what() const throw()
		{
			return ("The Grade is too high, maximum grade achievable: 1");
		}
	};
}
```

the 'what' function is declared in the exception.h file as: 'virtual const char *std::exception::what() const'

ex02
I have to consider grades of form, as const. Just initialization works for value assignment of `const` type. like for example in the copy constructor, I couldn't just assign those values to sth from src, cause they are const. Instead: 

![[Pasted image 20230429190839.png]]

when the copy assignment operator (`=`) is used to assign an object to another object, it may invoke the copy constructor to create a temporary copy of the object being assigned. This temporary copy is then used to perform the assignment.

**important**
If all of the attributes of a class are `const` private, it means they cannot be modified once initialized. In such a scenario, it is not possible to assign new values to these `const` attributes using the assignment operator (`operator=`).

Attempting to write an assignment operator for such a class would result in a compilation error, as you cannot modify `const` members.
