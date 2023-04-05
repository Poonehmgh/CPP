#include<iostream>

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return (0);
    }
    for (size_t i = 1; i < (size_t)argc; i++)
    {
        for(size_t j = 0; j < strlen(argv[i]); j++)
        {
            std::cout<<(char)toupper(argv[i][j]);
        }
        if (i != (size_t)argc -1)
            std::cout<<" ";
    }
    return (0);
}