#include<iostream>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPointer;
    std::string &stringRef = string;

    stringPointer = &string;
    std::cout<<"Memory address of string:\n"<<&string<<std::endl;
    std::cout<<"Memory address held by stringPointer:\n"<<stringPointer<<std::endl;
    std::cout<<"Memory address held by the stringRef:\n"<<&stringRef<<std::endl;
    std::cout<<"The value of string variable: "<<string<<"\nThe value pointed to by stringPointer:\n"<<*stringPointer \
            <<"\nThe value pointed to by stringRef:\n" <<stringRef<<std::endl;
}