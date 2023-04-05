#include<iostream>
class tv{
    public:
    int x;
    float y;
    std::string z;
    tv(int a, float b, std::string c);
    ~tv(void);
    void func(void);
};
tv::tv(int f, float g, std::string h): x(f), y(g), z(h){
    std::cout<<"constructor!"<<std::endl;
    std::cout<<"x is:"<<this->x<<std::endl;
    std::cout<<"y is:"<<this->y<<std::endl;
    std::cout<<"z is:"<<this->z<<std::endl;
    this->func();

}
tv::~tv()
{
    std::cout<<"deconstructor!"<<std::endl;
}
void tv::func(void)
{
    std::cout<<"member func!"<<std::endl;
}
int main()
{
    tv instance(30, 30.1, "Chert");
    std::cout<<"spadeee--------------------\n";
    tv instance2(29, 29.1, "Pert");
    return(0);
}