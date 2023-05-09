#include<iostream>
#include<fstream>
#include<sstream>

void    ft_replace(std::string *content, std::string s1, std::string s2, size_t pos)
{
    content->erase(pos, s1.length());
    content->insert(pos, s2);
}

int main(int argc, char **argv)
{
    if (argc != 4 )
    {
        std::cerr<<"error! bad input. enter <filename> <string 1> and <string 2>\n";
        return (1); // what is the convention? 
    }
    std::string file_name = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream inputFile(file_name);
    
    if (!inputFile.is_open())
        return (std::cerr<<"error in openning file.\n", 1);

    std::stringstream stringBuffer;
    stringBuffer << inputFile.rdbuf();
    std::string contents = stringBuffer.str();

    size_t pos = 0;
    while (s1 != "" && (pos = contents.find(s1, pos)) != std::string::npos) 
    {
        ft_replace(&contents, s1, s2, pos);
        pos += s2.length();
    }
    inputFile.close();

    std::ofstream outputFile(file_name.append(".replace"));
    if (!outputFile.is_open())
        return (std::cerr<<"error, unable to create output.\n", 1);
    outputFile<<contents;
    outputFile.close();
}