#ifndef _BINARY_SEARCH_DEFINITIONS_
#define _BINARY_SEARCH_DEFINITIONS_

#include "../../main.h"
#include "../search.h"

int binary_search(std::vector<int> * input, int target, int n, int acc = 0){
    if(n >= 1){
        int midIndex = acc + (n - acc) / 2;
        if(input->at(midIndex) == target)
            return midIndex;
        if(input->at(midIndex) > target)
            return binary_search(input, target, midIndex - 1);

        
        return binary_search(input, target, n, midIndex + 1);
    }
    return -1;
}

#endif