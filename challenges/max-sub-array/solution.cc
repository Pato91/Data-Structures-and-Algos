#include "./solution.h"

/**
 * Write an efficient program to find the sum of contiguous subarray 
 * within a one-dimensional array of numbers which has the largest sum.
 * 
 * Example
 * 
 * For the list [-2, -3, 4, -1, -2, 1, 5, -3], the maximum contiguous
 * array is [4, -1, -2, 1, 5] and it's sum is 7
*/

int main(){
    std::vector<int> instance = {-2, -3, 4, -1, -2, 1, 5, -3};
    // std::generate(instance.begin(), instance.end(), []() -> int {return rand() % 100; });
    std::tuple<int, int, int> max_sub_array = 
    max_contiguous_sub_array(instance, 0, (instance.size() - 1));

    printf(
        "\n\n Lowest index: %d\n Highest index: %d\n Largest sum: %d\n\n",
        std::get<0>(max_sub_array),
        std::get<1>(max_sub_array),
        std::get<2>(max_sub_array)
        );
    return 0;
}