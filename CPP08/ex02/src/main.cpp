#include "../inc/MutantStack.hpp"
#include <list>
#include <deque>

int main( void ) 
{
    {/*         test from subject file*/
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        // std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    {
        /*          test from subject but with list, they should give us same output. 
                    (some stack specific functions commented out in the prev example) */
        std::list<int> mlist;
        mlist.push_back(5);
        mlist.push_back(17);
        mlist.pop_back();
        std::cout << mlist.size() << std::endl;
        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);
        mlist.push_back(0);
        std::list<int>::iterator it = mlist.begin();
        std::list<int>::iterator ite = mlist.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    /*      my tests    */
    MutantStack<std::string> a;
    a.push("Ah! my Beloved, fill the Cup that clears");
    a.push("TO-DAY of past Regrets and future Fears-");
    a.push(" To-morrow?—Why, To-morrow I may be");
    a.push("Myself with Yesterday's Sev'n Thousand Years.");
    MutantStack<std::string>::container_type::iterator i; 
    for(i = a.begin(); i != a.end(); i++)
        std::cout << BLUE << *i << RESET << std::endl;
    std::cout << "----now the reverse iterator:----- \n";
    MutantStack<std::string>::container_type::reverse_iterator ri;
    for (ri = a.rbegin(); ri != a.rend(); ri++) // in reverse iterator, when you say ++, it means ++ in the reverse direction.
        std::cout << GREEN << *ri << RESET << std::endl;
    ri = a.rbegin(); // it is the last element
    std::cout << YELLOW << *ri << RESET << std::endl;    
}
