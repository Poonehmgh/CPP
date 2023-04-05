#include<iostream>

namespace poone{
    int var;
    std::string s;
    int func(void){
        return(1);
    }
}
namespace mgh{
    int var;
    std::string s;
    int func(void)
    {
        return(2);
    }
}
int var = -1;
std::string s = "minus one";
int func(void){
    return(-1);
}

int main()
{
    poone::var = 1;
    poone::s = "one";
    mgh::var = 2;
    mgh::s = "two";
    std::cout<<"NS poone:"<< poone::var<<"   "<< poone::s <<"   "<<poone::func()<<std::endl;

    std::cout<<"NS mgh:"<< mgh::var<<"   "<< mgh::s <<"   "<<mgh::func()<<std::endl;

    std::cout<<"NS global:"<< ::var<<"   "<< ::s <<"   "<<::func()<<std::endl;
}