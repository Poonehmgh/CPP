#include"../inc/phonebook.hpp"
#include <iomanip>
#include <string>

phonebook::phonebook()
{
    this->num_contacts = 0;
}


void    phonebook::phonebook_add()
{
    std::string str[5] = {"First Name: ", "Last Name: ", "Nick Name: ", "Number", "Darkest Secret: "};
    std::string prompt;
    contact     contact;
    int         index;

    index = this->num_contacts;
    for (int i = 0; i <= 4; i++)
    {
        std::cout<<"Enter "<<str[i]<<std::endl;
        getline(std::cin, prompt);
        str[i] = prompt;
    }
    contact.set_FirstName(str[0]);
    contact.set_LastName(str[1]);
    contact.set_NickName(str[2]);
    contact.set_Number(str[3]);
    contact.set_Secret(str[4]);
    if (contact.check_num())
    {
        std::cout<<"\033[0;31mInvalid number! Try again.\033[0m\n";
        return ;
    }
    if (contact.get_FirstName().empty() || contact.get_LastName().empty() \
        || contact.get_NickName().empty() || contact.get_NickName().empty() \
            || contact.get_Number().empty())
    {
        std::cout<<"\033[0;31mError! Field empty. Try again.\033[0m\n";
        return ;
    }
    if (index >= AMOUNT)
        index = index - AMOUNT;
    this->all[index] = contact;
    this->num_contacts++;
}

std::string    phonebook::format_check(std::string s)
{
    if (s.length() <= 10)
        return (s);
    return (s.substr(0,9).append("."));
}

void    phonebook::pb_print()
{
    int tmp;

    if (this->num_contacts <= AMOUNT)
        tmp = this->num_contacts;
    else
        tmp = 8;
    std::cout<<"\033[36m|"<<std::right<<std::setw(10)<<"Index";
    std::cout<<"|"<<std::right<<std::setw(10)<<"First Name";
    std::cout<<"|"<<std::right<<std::setw(10)<<"Last Name";
    std::cout<<"|"<<std::right<<std::setw(10)<<"Nick Name";
    std::cout<<"|"<<std::right<<std::setw(10)<<"Phone Number";
    std::cout<<"|"<<std::right<<std::setw(10)<<"Darkest Secret|\033[0m\n";
    for(int i = 0; i < tmp; i++)
    {
        std::cout<<"|"<<std::right<<std::setw(10)<<i + 1;
        std::cout<<"|"<<std::right<<std::setw(10)<<format_check(this->all[i].get_FirstName());
        std::cout<<"|"<<std::right<<std::setw(10)<<format_check(this->all[i].get_LastName());
        std::cout<<"|"<<std::right<<std::setw(10)<<format_check(this->all[i].get_NickName());
        std::cout<<"|"<<std::right<<std::setw(10)<<format_check(this->all[i].get_Number());
        std::cout<<"|"<<std::right<<std::setw(10)<<format_check(this->all[i].get_Secret())<<"|\n";
        
    }
}

void phonebook::phonebook_search()
{
    std::string prompt;
    int index;
    this->pb_print();
    if (!this->num_contacts)
    {
        std::cout<<"\033[0;31mError! Empty phonebook!\033[0m\n";
        return ;
    }
    std::cout<<"Choose the Index.\n";
    getline(std::cin, prompt);
    if (prompt.length() == 1 && prompt[0] > '0' && prompt[0] <= '8')
    {
        index = prompt[0] - '0';
        if (index > 0 && index <= this->num_contacts)
        {
            std::cout<<std::right<<"\033[0;32m"<<index<<"\n";
            std::cout<<std::right<<"First Name: "<<this->all[index - 1].get_FirstName()<<"\n";
            std::cout<<std::right<<"Last Name: "<<this->all[index - 1].get_LastName()<<"\n";
            std::cout<<std::right<<"Nick Name: "<<this->all[index - 1].get_NickName()<<"\n";
            std::cout<<std::right<<"Phone Number: "<<this->all[index - 1].get_Number()<< "\n"<<"Darkest Secret: "<<this->all[index - 1].get_Secret()<<"\033[0m";
        }
        else
            std::cout<<"\033[0;31mInvalid index! Try again.\033[0m\n";
        return ;
    }
    else
        std::cout<<"\033[0;31mInvalid index! Try again.\033[0m\n";    
    return ;
}