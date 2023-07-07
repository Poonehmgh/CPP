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



class btcMap
{
    public:
        // btcMap();
        // ~btcMap();
        // btcMap(btcMap const &src);
        // btcMap &operator=(btcMap    const &src);
        float find_value(int *key);
         void parse_input(std:: string input_fname);
         void date_check(int *date);
         void buchhaltung(std::string argv);
        class FailOpen: public std::exception
        {
            virtual const char *what() const throw()
            {
                return("Failed to open the file.");
            }
        };
        class DateOutOfRange: public std::exception
        {
            virtual const char *what() const throw()
            {
                return("Only the dates between 2009-01-02 and 2022-03-02 are available.");
            }
        };
        class DateDoesntExist: public std::exception
        {
            virtual const char *what() const throw()
            {
                return("Date doesnt exist on the calender.");
            }
        };
    private:
        std::map<std::tm, float> _map_;
};


#endif
