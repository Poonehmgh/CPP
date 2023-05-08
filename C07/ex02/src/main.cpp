# include "../inc/Array.hpp"


int main( void ) 
{
    // Array<int>  instance(1);
    // instance.setElement(42, 0);
    // // instance.setElement(420000, 1);
    
    // /*  call def const  */
    // Array<int> instance2;
    // /*      copy assinment operator and deep copying check */
    // instance2 = instance;
    // instance.~Array();
    // std::cout << instance2[0] << "\n";
    // /*  exceptions check */
    // std::cout << instance2.getElement(10) << "\n";
    // /*  [] operator check */
    // std::cout << instance2[0] << "\n";
    // std::cout << instance2[10] << "\n";
    // /*  adding more relements which is unacceptable bcz in the beginning we only told to have a certain size of array not more*/
    // for (int i = 0; i < 5; i++)
    //     instance2.setElement(i * 10 , i + 1);
    /*  another type    */
    Array<std::string>  str_1(5);
    Array<std::string>  str_2(1);
    for (int i = 0; i < 5; i++)
        str_1.setElement("sunny sky", i);
    // str_2[0] = str_1[1];
    //  std::cout << str_2[0]; I dont know why this line is not working !?!
    /*  index throw excep    */
    std::cout << str_1[10];
}