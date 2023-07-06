#include "../inc/PmergeMe.hpp"
#include<vector>


std::vector<int> merge(std::vector<int> one, std::vector<int> two)
{
    std::vector<int> three;

    while (one.size() != 0 && two.size() != 0)
    {
        if (one.at(0) > two.at(0))
        {
            three.push_back(two.at(0));
            two.erase(two.begin());
        }
        else
        { 
            three.push_back(one.at(0));
            one.erase(one.begin());
        }
    }
    while (one.size() != 0)
    {
        three.push_back(one.at(0));
        one.erase(one.begin());
    }
    while (two.size() != 0)
    {
        three.push_back(two.at(0));
        two.erase(two.begin());
    }
    return (three);
}

std::vector<int> merge_sort(std::vector<int> vect_arr)
{
    if (vect_arr.size() == 1)
        return (vect_arr);
    int size = vect_arr.size();
    std::vector<int>   array_one(vect_arr.begin(), vect_arr.begin() + size / 2);
    std::vector<int>    array_two(vect_arr.begin() + size / 2, vect_arr.end());
    array_one = merge_sort(array_one);
    array_two = merge_sort(array_two);

    return(merge(array_one, array_two));
}

std::vector<int> insertion_sort(std::vector<int> arr)
{
    int size = arr.size();
    int i;
    int j;

    for (i = 1; i < size; i++)
    {
        j = i;
        while (j > 0 && arr.at(j - 1) > arr.at(j))
        {
            int swap = arr.at(j - 1);
            arr.at(j - 1) = arr.at(j);
            arr.at(j) = swap;
            j--;
        }
    }
    return(arr);
}

void fordJohnsonSort(std::vector<int>& arr, int low, int high)
{
    if (low < high) {
        int mid = (low + high) / 2;
        
        if (mid - low + 1 <= 5) {
            insertion_sort(arr);
        } else {
            fordJohnsonSort(arr, low, mid);
            fordJohnsonSort(arr, mid + 1, high);
        }
        merge_sort(arr);
    }
}


int main(int argc, char **argv) 
{
    int test[] = {50, 5, 33, 0 , 12, 6, 120, 49, 9};
    std::vector<int> test_vect;
    int i = 0;
    while (i < 9)
    {
        test_vect.push_back(test[i]);
        i++;
    }
    // fordJohnsonSort(test_vect, 0, 8);
    // test_vect = merge_sort(test_vect);
    test_vect = insertion_sort(test_vect);
    for(std::vector<int>::iterator i = test_vect.begin(); i != test_vect.end(); i++)
        std::cout << *i << std::endl;
    // mergeInsertionSort(test);
    // if (argc <= 2)
    //     std::cerr << RED"wrong number of arguments!" << std::endl;
    (void)argv;
    (void)argc;
}
