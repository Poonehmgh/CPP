#include "../inc/btc.hpp"

btcMap::btcMap(){}

btcMap::~btcMap(){}

btcMap::btcMap(btcMap const &src)
{
    *this = src;
}

btcMap  &btcMap::operator=(btcMap const &src)
{
    _map_ = src._map_;
    return(*this);
}

void btcMap::find_value(date &key, float amount)
{
    if (amount < 0)
    {
        std::cerr << RED"Error: not a positive number." << RESET << std::endl;
        return ;
    }
    else if (amount > 1000)
    {
        std::cerr << RED"Error: amount too big." << RESET << std::endl;
        return ;
    }
    if (key.getYear() == -1)
    {
        std::cerr << RED"Error: bad input. date out of range. " << key.flag << RESET << std::endl;
        return;
    }    
    std::map<date, float>::iterator it_db;
    it_db = _map_.begin();
    while(it_db->first <= key && it_db != _map_.end())
        it_db++;
    it_db--;
    if (date_check(key))
    {
        std::cout << key.getYear() << "-" << key.getMonth() << "-" << key.getDay() \
        << " => " << amount << GREEN" = ";
        std::cout << it_db->second * amount << RESET << std::endl;
    }
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
    date time;
    getline(str_buff, line);
    while(!str_buff.eof())
    {
        getline(str_buff, line);
        if (line.find(" | ") == std::string::npos)
            std::cerr << RED"Error: each line has to contain \" | \" or \",\" between date and value." << RESET << std::endl;
        tmp = line.substr(0, line.find(" | "));
        float value = atof(line.substr(line.find(" | ") + 3, line.size() - 1).c_str());
        parse_date(tmp, time);
        find_value(time, value);
    }
}

int btcMap::date_check(date &key)
{
    if ((key.getYear() >= 2022 && key.getMonth() > 3) || key.getYear() < 2009)
        return(std::cerr << RED"Error: Date must be between 2009-01-02 and 2023-03-29" << RESET << std::endl, 0);
    /*  calender validity check */
    if ((key.getMonth() == 1 || key.getMonth() == 3 || key.getMonth() == 5 || key.getMonth() == 7 \
        || key.getMonth() == 8 || key.getMonth() == 10 || key.getMonth() == 12) && key.getDay() > 31)
        return(std::cerr << RED"Error: Date does not exist." << RESET << std::endl, 0);
    if ((key.getMonth() == 4 || key.getMonth() == 6 || key.getMonth() == 9 || key.getMonth() == 11) && key.getDay() > 30)
        return(std::cerr << RED"Error: Date does not exist." << RESET << std::endl, 0);    
    /*  leap year check     */
    if (key.getYear() % 4 == 0 && key.getMonth() == 2 && key.getDay() > 29)
        return(std::cerr << RED"Error: Date does not exist." << RESET << std::endl, 0);
    else if (key.getMonth() && key.getDay() > 28)
       return(std::cerr << RED"Error: Date does not exist." << RESET << std::endl, 0);
    return(1);
}

void btcMap::parse_date(std::string str, date &time)
{
    const char     *format = "%Y-%m-%d";
    std::tm timeStruct;
    std::memset(&timeStruct, 0, sizeof(struct tm)); // Initialize the struct with zeroes
    if (strptime(str.c_str(), format, &timeStruct))
    {
        time.setYear(timeStruct.tm_year + 1900);
        time.setMonth(timeStruct.tm_mon + 1);
        time.setDay(timeStruct.tm_mday);
    }
    else
    {
        time.setYear(-1);
        time.flag = str;
    }
}

void btcMap::process_input(std:: string input_file_name)
{
    std::ifstream   input_file(input_file_name);
    if (!input_file.is_open())
        throw(FailOpen());
    std::stringstream   str_buff;
    str_buff << input_file.rdbuf();
    std::string         line;
    std::string         tmp;
    date                time;
    
    int i = 0;
    while(!str_buff.eof())
    {
        getline(str_buff, line);
        if (!i++)
            continue;
        if (line.find(",") != std::string::npos)
        {
            tmp = line.substr(0, line.find(","));
            parse_date(tmp, time);
            float amount =  atof(line.substr(line.find(',') + 1, line.size() - 1).c_str());
            _map_.insert(std::make_pair(time, amount));
        }
        else
            throw(btcMap::InvalidFormat());
    }
}
