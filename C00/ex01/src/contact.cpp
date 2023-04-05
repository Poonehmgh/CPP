#include"../inc/contact.hpp"

int    contact::check_num()
{
    for (int i = 0; i < (int)this->_Num.length(); i++)
    {
        if (this->_Num[i] - '0' < 0 || this->_Num[i] - '0'> 9)
        {    
            if (i == 0 && this->_Num[i] == '+')
                continue ;
            else
                return (1);
        }
    }
    return (0);
}

std::string contact::get_FirstName(void)
{
    return (this->_FirstName);
}

void    contact::set_FirstName(std::string name)
{
    this->_FirstName = name;
}

std::string contact::get_LastName(void)
{
    return (this->_LastName);
}

void    contact::set_LastName(std::string lastname)
{
    this->_LastName = lastname;
}

std::string contact::get_NickName(void)
{
    return (this->_NickName);
}

void    contact::set_NickName(std::string nickname)
{
    this->_NickName = nickname;
}

std::string contact::get_Number(void)
{
    return (this->_Num);
}

void    contact::set_Number(std::string num)
{
    this->_Num = num;
}

std::string contact::get_Secret(void)
{
    return (this->_Secret);
}

void    contact::set_Secret(std::string secret)
{
    this->_Secret = secret;
}
