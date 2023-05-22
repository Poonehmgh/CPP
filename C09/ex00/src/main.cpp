#include "../inc/btc.hpp"
#include <map>
#include<fstream>
#include<sstream>

int main(int argc, char **argv) 
{
    if (argc != 2)
        std::cerr << RED"wrong number of arguments!" << std::endl;
    std::ifstream input_file(argv[1]);
    if (!input_file.is_open())
        return(std::cerr << "error in openning the file.\n", 1);
    std::stringstream   str_buff;
    str_buff << input_file.rdbuf();
    
}
