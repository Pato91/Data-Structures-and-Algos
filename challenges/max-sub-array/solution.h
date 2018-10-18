#ifndef _MAX_SUB_ARRAY_SOLUTION_
#define _MAX_SUB_ARRAY_SOLUTION_

#include "../../main.h"

/**
 * Write an efficient program to find the sum of contiguous subarray 
 * within a one-dimensional array of numbers which has the largest sum.
 * 
 * Example
 * 
 * For the list [-2, -3, 4, -1, -2, 1, 5, -3], the maximum contiguous
 * array is [4, -1, -2, 1, 5] and it's sum is 7
*/

std::tuple<int, int, int> max_crossing_sub_array(
    std::vector<int> list,
    int low,
    int middle,
    int max
){
    int left_sum = -1 * std::numeric_limits<int>::infinity();
    int left_most_index;
    int sum = 0;
    for(int i = middle; i >= low; --i){
        sum += list.at(i);
        if(sum > left_sum){
            left_sum = sum;
            left_most_index = i;
        }
    }

    int right_sum = -1 * std::numeric_limits<int>::infinity();
    int right_most_index;
    sum = 0;
    for(int i = middle + 1; i <= max; ++i){
        sum += list.at(i);
        if(sum > right_sum){
            right_sum = sum;
            right_most_index = i;
        }
    }

    sum = (left_sum + right_sum);

    return std::make_tuple(
        left_most_index,
        right_most_index,
        sum
    );
}

std::tuple<int, int, int> max_contiguous_sub_array(
    std::vector<int> list,
    int low,
    int max
){
    if(low == max)
        return std::make_tuple(low, max, list.at(low));
    else{
        int mid = (max + low) / 2;
        std::tuple<int, int, int> left 
        = max_contiguous_sub_array(list, low, mid);

        std::tuple<int, int, int> right
        = max_contiguous_sub_array(list, (mid + 1), max);

        std::tuple<int, int, int> cross
        = max_crossing_sub_array(list, low, mid, max);

        if(
            std::get<2>(left) >= std::get<2>(right) &&
            std::get<2>(left) >= std::get<2>(cross)
        )
            return left;

        if(
            std::get<2>(right) >= std::get<2>(left) &&
            std::get<2>(right) >= std::get<2>(cross)
        )
            return right;
        
        else
            return cross;
    }
}

#endif