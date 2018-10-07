#include "../main.h"

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

int main(){
    std::vector<int> instance(10000000);
    std::generate(instance.begin(), instance.end(), []() -> int {return rand() % 10000000;});
    auto start = std::chrono::high_resolution_clock::now();
    merge_sort(instance.begin(), instance.end());
    // merge_sort(instance.begin(), instance.end(), std::greater<> {}); // decending
    auto end = std::chrono::high_resolution_clock::now();
    double v = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    printf("\n\n");
    printf("\n\n\nTook %f seconds to execute\n\n\n", v/1000000);

}


/**
 * This is algorithm uses the devide and conquer strategy(break large problems into small ones
 * you then recursively merge sort). It runs in O(n * log(n))<worst case> meaning that for a given input of size n,
 * the running time grows by a factor log (n) indicating that it is efficient for large sized data sets.
 * 
 * A simple bench mark showed that; 
 *      
 *     Input size (n) | Algo sort order | Sorted? | input order | Running time (in seconds) | sorted Vs. unsorted   
 *     100            | INCR            | true    | DECR        | 0.000097                  | 1.47x                  
 *     100            | INCR            | false   | NONE        | 0.000143                  | 0x                
 *     100            | INCR            | true    | INCR        | 0.000080                  | 1.78x               
 *     100,000        | INCR            | true    | DECR        | 0.027157                  | 2.23x                  
 *     100,000        | INCR            | false   | NONE        | 0.060524                  | 0x               
 *     100,000        | INCR            | true    | INCR        | 0.025073                  | 2.41x          
 *     200,000        | INCR            | true    | DECR        | 0.053227                  | 1.77x                  
 *     200,000        | INCR            | false   | NONE        | 0.094476                  | 0x               
 *     200,000        | INCR            | true    | INCR        | 0.048212                  | 1.96x    
 *     1,000,000      | INCR            | true    | DECR        | 0.259986                  | 1.64x                  
 *     1,000,000      | INCR            | false   | NONE        | 0.425156                  | 0x               
 *     1,000,000      | INCR            | true    | INCR        | 0.233453                  | 1.82x    
 * 
 * In conclusion, the worst, best and average case senarios are relatively close in running time
 * Notice the best and avarage case times are just a few times faster.   
*/
