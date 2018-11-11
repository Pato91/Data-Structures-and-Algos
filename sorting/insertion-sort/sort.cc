#include "./sort.h"

int main(){
    std::vector<int> instance(100);
    generate_rand_values(&instance, 10000000);
    
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> res = insertion_sort(instance);
    auto end = std::chrono::high_resolution_clock::now();
    double v = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    // print_to_screen(res);
    printf("\n\n");
    printf("\n\n\nTook %f seconds to execute\n\n\n", v/1000000);
    // print_to_screen(insertion_sort(instance, "DESC"));
    // printf("\n\n");
    // printf("%d", find_element(instance, 4));
}


/**
 * This is a depth first algorithm and it is efficient when sorting small data sets.
 * It runs in O(n*n)<worst case> meaning that for a given input of size n,
 * the running time grows by a factor n indicating that it 
 * be inefficient for large sized data sets.
 * 
 * It's best case run time is when the input data set is already
 * sorted. It's worst case run time is when the input data is
 * sorted in the order reverse to the one the algo sorts the data.
 * A simple bench mark showed that; 
 *      
 *     Input size (n) | Algo sort order | Sorted? | input order | Running time (in seconds) | sorted Vs. unsorted | math time   
 *     100            | INCR            | true    | DECR        | 0.000215                  | 0x                  | an^2 + bn + c(quadratic time)
 *     100            | INCR            | false   | NONE        | 0.000167                  | 1.3x                | ~close to quadratic
 *     100            | INCR            | true    | INCR        | 0.000038                  | 4.7x                | an + b(linear time)
 *     100,000        | INCR            | true    | DECR        | 27.521112                 | 0x                  | an^2 + bn + c(quadratic time)
 *     100,000        | INCR            | false   | NONE        | 13.566058                 | 1.03x               | ~close to quadratic
 *     100,000        | INCR            | true    | INCR        | 0.004121                  | 6,677.3.0x          | an + b(linear time)
*/