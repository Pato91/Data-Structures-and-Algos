#include "./search.h"

int main(){
    std::vector<int> instance(1000000);
    std::generate(instance.begin(), instance.end(), []() -> int {return rand() % 1000000;});
    merge_sort(instance.begin(), instance.end());
    auto start = std::chrono::high_resolution_clock::now();
    int res = binary_search(&instance, instance.at(1002), instance.size());
    auto end = std::chrono::high_resolution_clock::now();
    double v = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    printf("%d", res);
    printf("\n\n");
    printf("\n\n\nTook %f seconds to execute\n\n\n", v/1000000);
    return 0;
}


/**
 * This is algorithm uses the devide and conquer strategy(break large problems into small ones
 * you then recursively search for the target by halving and shifting ranges). It runs in O(log(n))
 * <worst case> meaning that for a given input of size n, it finds the target in log(n) steps.
 * It is really efficient. For a list of 16 elements, you'd only need 4 steps ~ log base 2 of 16
 * ... list of 1,000 ~ 10 steps and list of 1,000,000 ~ 19 steps
 * 
 * Prerequisites 
 * -The list of items has to be sorted before hand
 * 
 * A simple bench mark showed that; 
 *      
 *     Input size (n) | list order | Running time (in seconds)   
 *     100            | INCR       | 0.000001                                    
 *     100,000        | INCR       | 0.000001                            
 *     200,000        | INCR       | 0.000001                                    
 *     1,000,000      | INCR       | 0.000002                         
*/