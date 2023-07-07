#include "../inc/btc.hpp"

int main(int argc, char **argv) 
{
    btcMap  src;
    try 
    {
        if (argc != 2)
            throw(btcMap::wrongArguments());
        src.process_input("data.csv");
        src.buchhaltung(argv[1]);
    }
    catch(std::exception &e)
    {
        std::cerr << RED"Error: " << e.what() << RESET << std::endl;
    }
}
