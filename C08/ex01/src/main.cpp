#include "../inc/Span.hpp"
#include <list>
#include <deque>

int main( void ) 
{
    /*  simple tests    */
    Span x(5);
    x.addNumber(10);
    x.addNumber(20);
    x.addNumber(30);
    x.addNumber(11);
    x.addNumber(100);
    std::cout << GREEN"shortest: " << x.shortestSpan() << RESET << std::endl;
    std::cout << YELLOW"longest span: " << x.longestSpan() << RESET << std::endl;

    /*    exceptions    */
    try
    {
        x.addNumber(200);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED"Exception thrown: " << e.what() << RESET"\n";
    }
    Span big(10000);
    for (int i = 0; i < 10000; i++)
        big.addNumber(rand() % 10000);
    std::cout << GREEN"shortest: " << big.shortestSpan() << RESET"\n";
    std::cout <<  YELLOW"longest: "<< big.longestSpan() << RESET"\n";
}
