#include"../inc/Harl.hpp"


void harl::_debug()
{
    std::cout<<"[DEBUG] :\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void harl::_info()
{
    std::cout<<"[INFO]:\nI cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldn\\’t be asking for more!\n";
}

void harl::_warning()
{
    std::cout<<"[WARNING] :\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";    
}

void harl::_error()
{
    std::cout<<"[ERROR] :\nThis is unacceptable! I want to speak to the manager now.\n";
}

void harl::complain(std::string level)
{
    std::string levels[4] = {"debug", "info", "warning", "error"};
    void    (harl::*funcPtr[4])() = {&harl::_debug, &harl::_info, &harl::_warning, &harl::_error};
    for(int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            // while (i < 4)
            // {
                (this->*funcPtr[i])();
            //     i++;
            // }
            // break;
        }
    }
}