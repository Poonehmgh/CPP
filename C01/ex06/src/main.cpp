#include"../inc/Harl.hpp"

int main(int argc, char **argv)
{
    harl instance;
    std::string order[4] = {"debug", "info", "warning", "error"};
    if (argc != 2)
        return(std::cerr<<"[ Probably complaining about insignificant problems ]" << std::endl, 1);
    int i = 0;
    while (i <= 3)
    {
        if (order[i] == argv[1])
            break;
        i++;
    }
    switch(i)
    {
        case 0:
            instance.complain("debug");
        case 1:
            instance.complain("info");
        case 2:
            instance.complain("warning");
        case 3:
            instance.complain("error");
        default:
            std::cerr<<"[ Probably complaining about insignificant problems ]" << std::endl;        
    }
}