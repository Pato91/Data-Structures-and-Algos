#ifndef _SELECTION_SORT_DEFINITIONS_
#define _SELECTION_SORT_DEFINITIONS_

#include "../../main.h"

std::vector<int> selection_sort_asc(std::vector<int> input){
    std::vector<int> *sorted = &input;
    int min;
    for(int i = 0; i < sorted->size(); ++i){
        min = sorted->at(i);
        for(int j = i + 1; j < sorted->size(); ++j){
            if(sorted->at(j) < min)
                std::iter_swap(&min, &sorted->at(j));
        }
    }
    return *sorted;
}

std::vector<int> selection_sort_desc(std::vector<int> input){
    std::vector<int> *sorted = &input;
    int min;
    for(int i = 0; i < sorted->size(); ++i){
        min = sorted->at(i);
        for(int j = i + 1; j < sorted->size(); ++j){
            if(sorted->at(j) > min)
                std::iter_swap(&min, &sorted->at(j));
        }
    }
    return *sorted;
}

std::vector<int> selection_sort(std::vector<int> input, std::string order = "ASC"){
    return order == "ASC" ? selection_sort_asc(input) : selection_sort_desc (input);
}

#endif