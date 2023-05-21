#include "../inc/easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main( void ) 
{
    /*  test a small vector of ints */

    const int values[] = { 1, 2, 3, 4, 5, 6, 7};
    size_t size = sizeof(values) / sizeof(values[0]);
    std::vector<int> containerInt(values, values + size); 
    std::cout << GREEN"Easy find 3: " << *easyFind(containerInt, 3) << RESET << std::endl;

    /*  test the vector that w/o value    */
    try {
        std::cout << "w/o value 200: " << *easyFind(containerInt, 200) << std::endl;
    } catch (std::exception &e)
    {
        std::cerr << RED"Excption thrown: " << e.what() << RESET << std::endl;
    }

    /*********  test 2 more different containers     ********/

    /*  defining containers    */
    std::list<int> intList;
    std::deque<int> intDeque;

    /*  filling the containers with random numbers  */
    for (int i = 0; i < 50; i++)
    {
        intList.push_back(std::rand() % 50);
        intDeque.push_back(std::rand() % 50);
    }
    // std::generate(intList.begin(), intList.end(), std::rand() % 50); // donno why didnt work
    // std::generate(intDeque.begin(), intDeque.end(), std::rand() % 50);
    
    /*      exception on list       */
    try {
        std::cout << "--------easy find on a list of ints container. with iterators-------\n";
        for (std::list<int>::iterator i = intList.begin(); i != intList.end(); i++)
            std::cout << GREEN << *i << *easyFind(intList, *i) <<RESET << std::endl;

        std::cout << "--------easy find on a deque of ints container. with numbers. it stops when some number is not found.-------\n";
        for (int i = 1; i < 50; i++)
            std::cout << YELLOW << *easyFind(intDeque, i) << RESET << std::endl;
        std::cout << "no such value: " << *easyFind(intList, 200) << std::endl;
    } catch (std::exception &e)
    {
        std::cerr << RED"Excption thrown: " << e.what() << RESET << std::endl;
    }




}
