#include<iostream>


class ex
{
    public:
    std::string str;
    void func2(int beta);
    int a;
    void    func(int alpha);
};
void ex::func2(int a)
{
    this->a = a * 2;
}
int main()
{
    int ex::*nump;
    void (ex::*function)(int beta);
    ex  instance;
    ex  instance2;
    int b;

    instance.a = 120;
    instance2.a = -120;
    nump = &ex::a;
    
    std::cout<<"i 1:"<<(instance.a)<<std::endl<<"i 2:"<<instance2.a<<std::endl;
    instance.*nump = 240;
    instance2.*nump = -240;
    function = &ex::func2;
    std::cout<<instance.a<<std::endl<<instance2.a<<std::endl;
    (instance.*function)(50);
    std::cout<<instance.a;

}