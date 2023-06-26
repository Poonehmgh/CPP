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
        void parse_input(std:: string input_fname);
        class FailOpen: public std::exception
        {
            virtual const char *what() const throw()
            {
                return("Failed to open the file.");
            }
        };
    private:
        std::map<std::array<int, 3>, float> _map_;
};


#endif
