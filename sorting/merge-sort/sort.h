#ifndef _MERGE_SORT_DEFINITIONS_
#define _MERGE_SORT_DEFINITIONS_

#include "../../main.h"

template <typename BidirIt, typename Compare = std::less<>>
void merge_sort(BidirIt first, BidirIt last, Compare com = Compare {}){
    const auto n = std::distance(first, last);

    if(n > 1){
        const auto middle = std::next(first, n / 2);

        merge_sort(first, middle, com);
        merge_sort(middle, last, com);

        std::inplace_merge(first, middle, last, com); // the merge stage
    }
};

#endif