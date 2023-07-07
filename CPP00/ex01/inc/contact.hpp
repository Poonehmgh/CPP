#ifndef CONTACT_H
# define CONTACT_H
#include <iostream>

class   contact
{
    public:
    
    std::string get_FirstName();
    void set_FirstName(std::string name);
    std::string get_LastName();
    void set_LastName(std::string last);
    std::string get_NickName();
    void set_NickName(std::string nickname);
    std::string get_Number();
    void set_Number(std::string num);
    std::string get_Secret();
    void set_Secret(std::string secret);
    int    check_num();

    private:

    std::string _FirstName;
    std::string _LastName;
    std::string _NickName;
    std::string _Num;
    std::string _Secret;
};

#endif