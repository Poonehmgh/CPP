#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# define AMOUNT 8
#include"../inc/contact.hpp"
class phonebook
{
    public:
        phonebook();
        void            phonebook_add();
        void            phonebook_search();
        std::string     format_check(std::string s);
        void            pb_print();
    private:
        int             num_contacts;
        contact         all[AMOUNT];
};

#endif