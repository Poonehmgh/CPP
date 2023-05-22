#include "../inc/Span.hpp"
#include <list>
#include <deque>

int main( void ) 
{
    /*  simple tests    */
    Span x(5);
    x.print_vector();
    x.addNumber(10);
    x.addNumber(20);
    x.addNumber(30);
    x.addNumber(11);
    x.addNumber(100);
    x.print_vector();
    std::cout << GREEN"shortest: " << x.shortestSpan() << RESET << std::endl;
    std::cout << YELLOW"longest span: " << x.longestSpan() << RESET << std::endl;

    // /*    exceptions    */
    try
    {
        x.addNumber(200);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED"Exception thrown: " << e.what() << RESET"\n";
    }
    /*      big vector  */
    // Span big(10000);
    // big.fillRandomNumber();
    // big.print_vector();
    // std::cout << GREEN"shortest: " << big.shortestSpan() << RESET"\n";
    // std::cout <<  YELLOW"longest: "<< big.longestSpan() << RESET"\n";
    // /*      subj test      */
    // Span sp = Span(5);
    // sp.addNumber(6);
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);
    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;
    /*      test for empty container    */
    // Span y;
    // try
    // {
    //     y.addNumber(10);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << RED"Exception thrown: " << e.what() << RESET"\n";
    // }  
}
