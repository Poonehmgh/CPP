#include"../inc/Harl.hpp"

int main()
{
    harl instance;

    instance.complain("debug");
    instance.complain("info");
    instance.complain("warning");
    instance.complain("error");
    instance.complain("not match");

}