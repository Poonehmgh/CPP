#include<iostream>


void constref(std::string const &ballsref)
{
    std::cout<<"\nA:\n"<<ballsref;
    // ballsref = "basketballs";
}
int main()
{
    std::string balls;
    std::string balls2;
    std::string *ballsp;
    std::string &ballsref = balls;

    balls = "footballs";
    ballsp = &balls;
    std::cout<<"\nballs: "<<balls<<"\nballsp :"<< *ballsp<< "\nballs ref :"<<ballsref;
    ballsref = "vollyballs";
    ballsref = balls2;
    std::cout<<"\nballs: "<<balls<<"\nballsp :"<< *ballsp<< "\nballs ref :"<<ballsref;
    constref(balls);

}