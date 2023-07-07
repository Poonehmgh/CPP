# include "../inc/abcd.hpp"

int main()
{
    Base *ptr = generate();
    Base &refr = *ptr;
    identify(ptr);
    identify(refr);
    delete ptr;
    return (0);
}