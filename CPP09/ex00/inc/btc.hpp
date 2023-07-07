#ifndef BTC_H
#define BTC_H
#include<iostream>
# define  GREEN "\x1B[1;32m"
# define YELLOW "\x1B[1;33m"
# define  RESET "\x1B[0;37m"
# define BLUE  "\033[36m"
# define RED    "\033[0;31m"
#include <algorithm>
#include <exception>
#include <map>
#include<fstream>
#include<sstream>
#include<time.h>
#include"date.hpp"

class btcMap
{
    public:
        btcMap();
        ~btcMap();
        btcMap(btcMap const &src);
        btcMap &operator=(btcMap    const &src);
        void parse_date(std::string str, date &time);
        void find_value(date &date, float amount);
        void process_input(std:: string input_fname);
        int date_check(date &date);
        void buchhaltung(std::string argv);
        class FailOpen: public std::exception
        {
            virtual const char *what() const throw()
            {
                return("Failed to open the file.");
            }
        };
        class wrongArguments: public std::exception
        {
            virtual const char *what() const throw()
            {
                return("Wrong number of arguments.");
            }
        };
        class InvalidFormat: public std::exception
        {
            virtual const char *what() const throw()
            {
                return("Date format must contain ',' in each line for database and '|' in each line for input file and the separator between date and value.");
            }
        };
    private:
        std::map<date, float> _map_;
        std::map<date, float> _input_;
};


#endif
