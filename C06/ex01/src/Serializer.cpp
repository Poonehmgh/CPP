# include "../inc/Serializer.hpp"
# include <string>
# include <cctype>
# include <limits.h>
# include <iomanip>

Serializer::Serializer()
{
    std::cout << "Serializer default constructir is called.\n";
}

Serializer::~Serializer()
{
    std::cout << "Serializer destructor is called.\n";
}

Serializer::Serializer(Serializer   const &src)
{
    *this = src;
}

Serializer  &Serializer::operator=(Serializer   const &src)
{
    std::cout << "Serializer copy assignment is called.\n"; 
    (void)src;   
    return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
    uintptr_t   address = reinterpret_cast<uintptr_t>(ptr);
    return (address);
}

Data * Serializer::deserialize(uintptr_t raw)
{
    Data *tmp = reinterpret_cast<Data *>(raw);
    return (tmp);
}