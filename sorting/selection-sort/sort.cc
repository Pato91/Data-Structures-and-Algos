#include "../../main.h"

std::vector<int> selection_sort_asc(std::vector<int> input);
std::vector<int> selection_sort_desc(std::vector<int> input);
std::vector<int> selection_sort(std::vector<int> input, std::string order = "ASC");

int main(){
    std::vector<int> instance(200000);
    std::generate(instance.begin(), instance.end(), []() -> int {return rand() % 200000;});
    
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> res = selection_sort(instance);
    auto end = std::chrono::high_resolution_clock::now();
    double v = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    // print_to_screen(res);
    printf("\n\n");
    printf("\n\n\nTook %f seconds to execute\n\n\n", v/1000000);
}

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

std::vector<int> selection_sort(std::vector<int> input, std::string order){
    return order == "ASC" ? selection_sort_asc(input) : selection_sort_desc (input);
}

/**
 * This is efficient when sorting small data sets.
 * It runs in O(n*n)<worst case, best case, average> meaning that for a given input of size n,
 * the running time grows by a factor n indicating that it 
 * be inefficient for large sized data sets.
 * 
 * A simple bench mark showed that; 
 *      
 *     Input size (n) | Algo sort order | Sorted? | input order | Running time (in seconds) | sorted Vs. unsorted   
 *     100            | INCR            | true    | DECR        | 0.000340                  | 0x                  
 *     100            | INCR            | false   | NONE        | 0.000340                  | 0x                
 *     100            | INCR            | true    | INCR        | 0.000340                  | 0x               
 *     100,000        | INCR            | true    | DECR        | 0.601602                  | 0x                  
 *     100,000        | INCR            | false   | NONE        | 0.601602                  | 0x               
 *     100,000        | INCR            | true    | INCR        | 0.601602                  | 0x          
 *     200,000        | INCR            | true    | DECR        | 264.960646                | 0x                  
 *     200,000        | INCR            | false   | NONE        | 264.960646                | 0x               
 *     200,000        | INCR            | true    | INCR        | 264.960646                | 0x    
 * 
 * The O(n * n) growth we see from 100 -> 100,000 -> 200,000 is so drastic!     
*/



