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

// void fordJohnsonSort(std::vector<int>& arr, int low, int high)
// {
//     if (low < high) {
//         int mid = (low + high) / 2;
        
//         if (mid - low + 1 <= 5) {
//             std::vector<int> tmp(arr.at(low), arr.at(mid));
//             insertion_sort(tmp);
//         } else {
//             fordJohnsonSort(arr, low, mid);
//             fordJohnsonSort(arr, mid + 1, high);
//         }
//         merge_sort(arr);
//     }
// }
std::vector<int> ford_johnson_merge_insert(std::vector<int> arr)
{
    int size = arr.size();

    if (size <= 1)
        return arr;

    std::vector<int> sorted;

    for (int i = 0; i < size; i += 1) {
        int end = std::min(i + 1, size);
        std::vector<int> chunk(arr.begin() + i, arr.begin() + end);
        chunk = insertion_sort(chunk);
        sorted = merge(sorted, chunk);
    }

    return sorted;
}

int main(int argc, char **argv) 
{
    std::vector<int> test_vect;
    int i = 0;
    while (i < argc)
    {
        test_vect.push_back(atoi(argv[i]));
        i++;
    }
    test_vect = ford_johnson_merge_insert(test_vect);
    for(std::vector<int>::iterator i = test_vect.begin(); i != test_vect.end(); i++)
        std::cout << *i << std::endl;
    // mergeInsertionSort(test);
    // if (argc <= 2)
    //     std::cerr << RED"wrong number of arguments!" << std::endl;
    (void)argv;
    (void)argc;
}
