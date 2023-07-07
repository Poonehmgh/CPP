# include "../inc/abcd.hpp"

Base::~Base()
{
    std::cout << "Base destructor is called.\n";
}

Base *generate(void)
{
    time_t t;
    Base *ptr;
    switch(time(&t) % 3)
    {
        case 0:
            ptr = new A;
            std::cout << GREEN"Type A is generated.\n" << RESET;
            break;
        case 1:
            ptr = new B;
            std::cout << GREEN"Type B is generated.\n" << RESET;
            break;
        case 2:
            ptr = new C;
            std::cout << GREEN"Type C is generated.\n" << RESET;
            break;
    }
    return (ptr);
}

void identify(Base *p)
{
    A   *Aptr = dynamic_cast<A *>(p);
    B   *Bptr = dynamic_cast<B *>(p);
    C   *Cptr = dynamic_cast<C *>(p);
    if (Aptr)
        std::cout << Aptr << YELLOW"\nType was: A\n" << RESET;
    else if (Bptr)
        std::cout << Bptr << YELLOW"\nType was: B\n" << RESET;
    else if (Cptr)
        std::cout << Cptr << YELLOW"\nType was: C\n" << RESET;
    else
        std::cout << RED"cast unsuccessfull\n" << RESET;
}

void identify(Base &p)
{
    try
    {
        A   &Aptr = dynamic_cast<A &>(p);
        std::cout << &Aptr << YELLOW"\nType was: A\n" << RESET;
    }
    catch(std::exception &e)
    {
        try
        {
             B   &Bptr = dynamic_cast<B &>(p);
             std::cout << &Bptr << YELLOW"\nType was: B\n" << RESET;
        }
        catch(std::exception &e)
        {
            try
            {
                 C   &Cptr = dynamic_cast<C &>(p);
                 std::cout << &Cptr << YELLOW"\nType was: C\n" << RESET;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << RED"input is same as: none of the types A, B, C\n" << RESET;
            }
        }
    }
}