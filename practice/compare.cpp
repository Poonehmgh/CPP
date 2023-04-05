#include<iostream>

class pc
{
    public:
    pc(int Num);
    ~pc(void);
    void setNum(int a);
    int getNum(void) const;
    int compare(pc *other) const;
    private:
    int _Num_;
};

pc::pc(int Num): _Num_(Num)
{
    std::cout<<"constructor called."<<std::endl;
    _Num_ = Num;
}
pc::~pc(void)
{
    std::cout<<"deconstructor called."<<std::endl;
}
int pc::getNum(void) const
{
    return(_Num_);
}
void pc::setNum(int x)
{
    _Num_ = x;
}
int pc::compare(pc *other)const
{
    if (&this->_Num_ == &other->_Num_)
        std::cout<<"same physically."<<std::endl;
    else
        std::cout<<"not same physically."<<std::endl;
    if (this->_Num_ == other->_Num_)
    {
        std::cout<<"same content."<<std::endl;
        return (0);
    }
    else
    {
        std::cout<<"not equal."<<std::endl;
        return(1);
    }  
}

int main()
{
    pc  sample(30);
    pc  sample2(1238);
    pc  sample3(1238);
    pc  *sample4;
    sample4 = &sample;  // if I define it as a pointer (pc *sample 4), I can make it point to address of sample. but if I define it as "pc sample4",
    //and then do this: "sample4 = sample" it wont be same physically. it wont point to the same address. it only makes its content equal to each other.
    // std::cout<<"sampe num: "<<sample.getNum()<<std::endl;
    // sample.setNum(55);
    // std::cout<<"sampe num: "<<sample.getNum()<<std::endl;
    // sample.compare(&sample2);
    // sample2.compare(&sample3);
    // sample2.compare(&sample2);
    sample.compare(sample4);
}