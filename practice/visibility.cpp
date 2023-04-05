#include<iostream>

class sample{
    public:
    int key;
    std::string s;
    sample(int key);
    ~sample(void);
    private:
    int _key;
    std::string _s;
    void _func(int key);
};

sample::sample(int a){
    _key = a;
    a++;
    _key = a;
    std::cout<<"constructorcalled\n"<<"this key:"<<this->_key<<std::endl;
}
sample::~sample(void)
{
    std::cout<<"deconst called!\n";
}
void sample::_func(int key)
{
    std::cout<<"private func called!\n";
}
int main()
{
    sample A(12);
    A._s = "hello";
    std::cout<<"aaaaa "<<A.s;
}