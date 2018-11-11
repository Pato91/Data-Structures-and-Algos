#include "./sort.h"

int main(){
    std::vector<int> instance(200000);
    generate_rand_values(&instance, 200000);
    
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> res = selection_sort(instance);
    auto end = std::chrono::high_resolution_clock::now();
    double v = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    // print_to_screen(res);
    printf("\n\n");
    printf("\n\n\nTook %f seconds to execute\n\n\n", v/1000000);
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



