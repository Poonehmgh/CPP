#include<iostream>

/* when we wanna have a non member attribute, we treat it like it is outside the class. means that when we wanna address it, we address 
it like this :  
class::nonmember
also, it acts on the class level not on the instance level. meaning that we dont do: class.nonmem 
we do:
class::nonmem
also, we initialize it outside. the "static" word is a keyword for us to signal the class that this is a nonmember attribute and it acts as a 
general variable in all the instances. the static keyword is only used in the class, when defining. initialization taekes place like aglobal variable
without the static word.
*/
class bottle{
    public:
    bottle(void);
    ~bottle(void);
    static int getnonmem_counter(void);
    private:
    static int nonmem_counter;
};
int bottle::nonmem_counter = 0;
bottle::bottle(void)
{
    std::cout<<"const called.\n";
    bottle::nonmem_counter++;
    return;
}
bottle::~bottle(void)
{
    std::cout<<"destr called.\n";
    bottle::nonmem_counter--;
    return;
}
int  bottle::getnonmem_counter(void)
{
    return(bottle::nonmem_counter);
}
void func()
{
    bottle a;
    std::cout<<"inside: "<<bottle::getnonmem_counter();
}
int main()
{
    // bottle a;
    std::cout<<"s1? "<<bottle::getnonmem_counter()<<"\n";
    func();
    // bottle b;
    std::cout<<"s2? "<<bottle::getnonmem_counter()<<"\n";
    std::cout<<"s3? "<<bottle::getnonmem_counter()<<"\n";
    
}