#include<iostream>

class lind
{
    public:
    lind(); //constructor;
    lind(int a, int b); //constructor with overloading
    ~lind(); //destructor
    lind(lind const &src); //copy constructor
    lind &operator=(lind const &src);
    int get_a();
    int get_b();
    private:
    int _a;
    int _b;
};

lind::lind(){
    std::cout<<"default const\n";
}
lind::lind(int a, int b): _a(a), _b(b)
{
    std::cout<<"param constructor called.\n";
}
lind::~lind(){std::cout<<"destructor called.\n";}
lind::lind(lind const &src)
{
    *this = src;
}
lind &lind::operator=(lind const &src)
{
    _a = src._a;
    _b = src._b;
    return(*this);
}
int lind::get_a(void)
{
    return(_a);
}
int lind::get_b()
{return(_b);}
int main()
{
    lind instance; //pas mifahmim ke mishe ham const avvali roo khoond ham dovomi.
    lind instance2(1, 2);
    instance.operator=(instance2);
    std::cout<<"operation:"<<instance.get_a()<<"    "<<instance.get_b();
    lind instance3(instance);
    std::cout<<"\nthe copy constructor, which copies a total instance in the new one:\n"<<instance3.get_a()<<"     "<<instance3.get_b();

}