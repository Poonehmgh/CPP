#ifndef Serializer_h
# define Serializer_h
# include<iostream>
# include <exception>
# define  GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define  RESET "\e[0;37m"
# define BLUE  "\033[36m"
# define RED    "\033[0;31m"

typedef struct data
{
    int random;
    std::string random_str;
} Data;


class Serializer
{
    public:
        Serializer();
        ~Serializer();
        Serializer(Serializer   const &src);
        Serializer   &operator=(Serializer   const &src);
        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);
};


#endif
