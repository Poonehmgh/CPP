#include "../inc/btc.hpp"



int main(int argc, char **argv) 
{
    btcMap  map;
    // std::map<std::string, float> src;
    if (argc != 2)
        std::cerr << RED"wrong number of arguments!" << std::endl;
 
    map.parse_input(argv[1]);
    // std::pair<std::string, float> pair[] ={std::make_pair("B", 2), std::make_pair("C", 3), std::make_pair("D", 4)};
    // std::map<std::string, float> map1(pair, pair + sizeof(pair)/ sizeof(pair[0]));
    // map1.insert(std::make_pair("B", 1));

    // for (std::map<std::string, float>::iterator i = map1.begin(); i != map1.end(); i++ )
    //     std::cout << "key: " << i->first << " value : " << i->second << std::endl;

}
