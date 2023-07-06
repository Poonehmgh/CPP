#include "../inc/PmergeMe.hpp"
#include<vector>


std::vector<int> merge(std::vector<int> arr, int left, int mid, int right)
{
    std::vector<int> three;
    std::vector<int> one_tmp(arr.at(left), arr.at(mid));
    std::vector<int> two_tmp(arr.at(mid + 1), arr.at(right));

    while (!one_tmp.empty() && two_tmp.size() != 0)
    {
        if (one_tmp.at(0) > two_tmp.at(0))
        {
            three.push_back(two_tmp.at(0));
            two_tmp.erase(two_tmp.begin());
        }
        else
        { 
            three.push_back(one_tmp.at(0));
            one_tmp.erase(one_tmp.begin());
        }
    }
    while (one_tmp.size() != 0)
    {
        three.push_back(one_tmp.at(0));
        one_tmp.erase(one_tmp.begin());
    }
    while (two_tmp.size() != 0)
    {
        three.push_back(two_tmp.at(0));
        two_tmp.erase(two_tmp.begin());
    }
    return (three);
}

std::vector<int> merge_sort(std::vector<int> vect_arr, int left, int mid, int right)
{
    if (vect_arr.size() == 1)
        return (vect_arr);
    // int size = vect_arr.size();
    std::vector<int>   array_one(vect_arr.at(left), vect_arr.at(mid));
    std::vector<int>    array_two(vect_arr.at(mid + 1), vect_arr.at(right));
    array_one = merge_sort(array_one, left, (mid - left) / 2, mid);
    array_two = merge_sort(array_two, mid + 1, (right - mid - 1) / 2, right);

    return(merge(vect_arr, left, mid, right));
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
//             insertion_sort(arr);
//         } else {
//             fordJohnsonSort(arr, low, mid);
//             fordJohnsonSort(arr, mid + 1, high);
//         }
//         merge_sort(arr);
//     }
// }


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
    // fordJohnsonSort(test_vect, 0, test_vect.size() - 1);
    test_vect = merge_sort(test_vect, 0 , 4, 8);
    // test_vect = insertion_sort(test_vect);
    for(std::vector<int>::iterator i = test_vect.begin(); i != test_vect.end(); i++)
        std::cout << *i << std::endl;
    // mergeInsertionSort(test);
    // if (argc <= 2)
    //     std::cerr << RED"wrong number of arguments!" << std::endl;
    (void)argv;
    (void)argc;
}
