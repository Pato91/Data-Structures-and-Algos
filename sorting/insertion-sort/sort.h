#ifndef _INSERTION_SORT_DEFINITIONS_
#define _INSERTION_SORT_DEFINITIONS_

#include "../../main.h"

std::vector<int> insertion_sort_asc(std::vector<int> input){
    std::vector<int> sorted;
    sorted.push_back(input.at(0));
    for(int i = 1; i < input.size(); ++i){
        int current_element = input[i];
        sorted.push_back(current_element);
        int j = i - 1;
        while(sorted[j] > current_element){
            sorted[j+1] = sorted[j];
            j -= 1;
        }
        sorted[j+1] = current_element;
    }
    return sorted;
}

std::vector<int> insertion_sort_desc(std::vector<int> input){
    std::vector<int> sorted;
    sorted.push_back(input.at(0));
    for(int i = 1; i < input.size(); ++i){
        int current_element = input[i];
        sorted.push_back(current_element);
        int j = i - 1;
        while(j > -1 && current_element > sorted[j]){
            sorted[j+1] = sorted[j];
            j -= 1;
        }
        sorted[j+1] = current_element;
    }
    return sorted;
}

std::vector<int> insertion_sort(std::vector<int> input, std::string order  = "ASC"){
    return order == "ASC" ? insertion_sort_asc(input) : insertion_sort_desc(input);;
}

int find_element(std::vector<int> input, int target){
    int result;
    for(int i = 0; i < input.size(); ++i){
        if(input[i] == target){
            result = i;
            break;
        }
        else if(i == input.size() - 1 && input[i] != target)
            result = -1;
    }
    return result;
}

void insertion_sort_recursive_asc(std::vector<int> * input, int n){
    if(n <= 1)
        return;
    insertion_sort_recursive_asc(input, n-1);
    int curr_element = input->at(n-1);
    int j = n - 2;

    while(j >= 0 && input->at(j) > curr_element){
        input->at(j + 1) = input->at(j);
        j -= 1;
    }
    input->at(j+1) = curr_element;
}

#endif