#include"../inc/phonebook.hpp"

int main()
{
    phonebook   user_pb;
    std::string    prompt;
    
    while (true)
    {
        std::cout<<"\nEnter command: ADD or SEARCH or EXIT.\n";
        getline(std::cin, prompt);
        if (prompt == "ADD")
            user_pb.phonebook_add();
        else if (prompt == "SEARCH")
            user_pb.phonebook_search();
        else if (prompt == "EXIT")
            break ;
        else
            std::cout<<"\033[0;31mInvalid command! Try again.\033[0m\n";
    }
    return (0);
}