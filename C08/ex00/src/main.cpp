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

    // /*********  test 3 different containers     ********/

    // /*  defining containers with 50 elements    */
    // std::vector<int> intVec(50);
    // std::list<int> intList(50);
    // std::deque<int> intDeque(50);

    // /*  filling the containers with random numbers  */
    // std::generate(intVec.begin(), intVec.end(), std::rand() % 50);
    // std::generate(intList.begin(), intList.end(), std::rand() % 50);
    // std::generate(intDeque.begin(), intDeque.end(), std::rand() % 50);





}
