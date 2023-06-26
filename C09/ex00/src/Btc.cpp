#include "../inc/btc.hpp"


void btcMap::parse_input(std:: string input_file_name)
{
    std::ifstream input_file(input_file_name);
    if (!input_file.is_open())
        throw(FailOpen());
    std::stringstream   str_buff;
    str_buff << input_file.rdbuf();
    std::string line;
    std::string     tmp;
    const char     *format = "%Y-%m-%d";
    std::tm timeStruct;
    std::memset(&timeStruct, 0, sizeof(struct tm)); // Initialize the struct with zeroes
    int i = 0;
    int *tmp2 = new(int[3]);
    while(!str_buff.eof())
    {
        getline(str_buff, line);
        if (!i++)
            continue;
        if (line.find(" | ") != std::string::npos)
        {
            tmp = line.substr(0, line.find(" | "));
            if (strptime(tmp.c_str(), format, &timeStruct) == nullptr)
            {
                std::cout << "failed\n";
                tmp2[0] = timeStruct.tm_year + 1900;
                tmp2[1] = timeStruct.tm_mon + 1;
                tmp2[2] = timeStruct.tm_mday;
                _map_.insert(std::make_pair(tmp2, -1));
            }
            else
            {
                std::string value_str = line.substr(line.find("| ") + 1, line.size() - 1);
                float value = atof(value_str.c_str());
                tmp2[0] = timeStruct.tm_year + 1900;
                tmp2[1] = timeStruct.tm_mon + 1;
                tmp2[2] = timeStruct.tm_mday;
                _map_.insert(std::make_pair(tmp2, value));
            }
        }
        else
            std::cout  << "invalid!" << std::endl;
    }
    std::map<int *, float>::iterator ii = _map_.begin();
    while(ii != _map_.end())
    {
        std::cout << ii->first[0] << "  m: " << ii->first[1] << "  d: " << ii->first[2] << "   value: " << ii->second << std::endl;
        ii++;
    }
}
