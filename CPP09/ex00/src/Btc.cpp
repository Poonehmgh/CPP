#include "../inc/btc.hpp"

float btcMap::find_value(int *key)
{
    std::map<int *, float>::iterator it = _map_.find(key);
    if (it != _map_.end())
        return(it->second);
    else
        throw(btcMap::DateDoesntExist());
}

void    btcMap::buchhaltung(std::string argv)
{
    std::ifstream input_file(argv);
    if (!input_file.is_open())
        throw(FailOpen());
    std::stringstream   str_buff;
    str_buff << input_file.rdbuf();
    std::string line;
    std::string tmp;
    while(!str_buff.eof())
    {
        getline(str_buff, line);
        tmp = line.substr(0, line.find(" | "));
        try
        {
        int *tmp2;
        tmp2[0] = 2012;
        tmp2[1] = 2;
        tmp2[2] = 3;
        float value = find_value(tmp2);
        std::cout << "YY" << value << std::endl;
        }
        catch(std::exception &e)
        {
            std::cout << "hell " << e.what() << RESET << std::endl;
        }
    }

}


void btcMap::date_check(int *date)
{
    /* database range check */
    if (date[0] < 2009 || date[0] > 2022)
        throw(btcMap::DateOutOfRange());
    if (date[0] == 2022 && date[1] > 3)
        throw(btcMap::DateOutOfRange());
    /*  calender validity check */
    if ((date[1] == 1 || date[1] == 3 || date[1] == 5 || date[1] == 7 \
        || date[1] == 8 || date[1] == 10 || date[1] == 12) && date[2] > 31)
        throw(btcMap::DateDoesntExist());
    if ((date[1] == 4 || date[1] == 6 || date[1] == 9 || date[1] == 11) && date[2] > 30)
        throw(btcMap::DateDoesntExist());    
    /*  leap year check     */
    if (date[0] % 4 == 0 && date[1] == 2 && date[2] > 29)
        throw(btcMap::DateDoesntExist());
    else if (date[1] && date[2] > 28)
        throw(btcMap::DateDoesntExist());
}

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
        if (line.find(",") != std::string::npos)
        {
            tmp = line.substr(0, line.find(","));
            if (strptime(tmp.c_str(), format, &timeStruct))
            {
                tmp2[0] = timeStruct.tm_year + 1900;
                tmp2[1] = timeStruct.tm_mon + 1;
                tmp2[2] = timeStruct.tm_mday;
                // std::cout << tmp2[0] << " " << tmp2[1] << " " << tmp2[2] << std::endl;
                try
                {
                    // date_check(tmp2);
                    // _map_.insert(std::make_pair(tmp, atof(line.substr(line.find(',') + 1, line.size() - 1).c_str())));
                    _map_.insert(std::make_pair(timeStruct, atof(line.substr(line.find(',') + 1, line.size() - 1).c_str())));
                }catch(std::exception &e)
                {
                    std::cerr << RED"Error: " << e.what() << RESET << std::endl;
                }
            }
            else
            {
                //if it recognizes an invalid date, it doesnt update the date values of time struct. or it fills it with garbage values
                std::cout << RED"failed" << std::endl;          
            }
        }
        else
            std::cout  << "invalid format!" << std::endl;
    }
    //remove temp 2
}
