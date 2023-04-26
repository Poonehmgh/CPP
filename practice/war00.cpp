#include <string>
#include <vector>
#include<iostream>

// std::vector<std::string> solution(const std::string &s)
// {
//   std::vector<std::string>  arr;
//   char tmp[2];
//   for (int i = 0; i < s.size(); i++)
//     {
//       if (s[i + 1])
//        {
//         tmp[0] = s[i];
//         tmp[1] = s[i+1];}
//       else
//         {tmp[0] = s[i];
//         tmp[1]= '_';}
//     arr.push_back(tmp);
//     i++;
//   }
//     return(arr);
// }

std::vector<std::string> solution(std::string const &s)
{
    std::vector<std::string> res;
    for (int i = 0; i < s.length(); i+=2)
    {
        res.push_back(s.substr(i, 2));
        if (s.length() % 2)
        res[res.size() - 1] += "_";
    }
    return(res);
}

int main()
{
    std::vector<std::string> res;
    const std::string s = "abc";
    res = solution(s);
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << res[i] << "\n";
    }
    
}