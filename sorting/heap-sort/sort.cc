#include "./sort.h"

int main(){
    std::vector<int> instance(1000000);
    generate_rand_values(&instance, 10000000);
    Heap heap;
    heap.list = &instance;
    // heap_sort(&heap);
    // std::reverse(heap.list->begin(), heap.list->end());
    auto start = std::chrono::high_resolution_clock::now();
    heap_sort(&heap);
    auto end = std::chrono::high_resolution_clock::now();
    double v = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    // print_to_screen(*heap.list);
    printf("\n\n");
    printf("\n\n\nTook %f seconds to execute\n\n\n", v/1000000);
}



/**
 * This is algorithm is based of the data structure called a heap(specifically a binary heap). A binary
 * heap is basically an array object we can view as a nearly complete binary tree. A binary tree is a tree
 * in which every parent node has a maximum of two leaf nodes or children.
 * 
 * A data structure that represents a heap will have two properties; arr.length and arr.heap_size where
 * arr is the heap's array object and o <= arr.heap_size <= arr.length (meaning not all array element)
 * will be in the heap.
 * 
 * There are two types of heaps; a max heap(this current implementaion) and a min heap.
 *      - max heap fulfills the property arr[parent(i)] >= arr[i] where parent(i) = floor(i/2);
 *      - min heap fulfills the property arr[parent(i)] <= arr[i] where parent(i) = floor(i/2);
 * 
 * Height of the heap is O(log n)
 * There three basic procedures that can be done on a heap;
 *      - max_heapify or min_heapify takes O(log n) time
 *      - build_max_heap or build_min_heap runs in linear time ( O(n) )
 *      - heap_sort which runs in O(n log n) time and sorts the heap array object
 *      
 *      -others are max_heap_insert, heap_extract_max, heap_increase_key and heap_maximum that run in O(log n) each
 *       to allow the heap data structure to implement a priority queue.
 * 
 * Heap sort runs in O(n log n) as stated above because it combines the build_max_heap or build_min_heap procedure
 * call with the max_heapify or min_heapify procedure call.
 * 
 * A simple bench mark showed that; 
 *      
 *     Input size (n) | Sorted? | input order | Running time (in seconds) | sorted Vs. unsorted   
 *     100            | true    | DECR        | 0.000101                  | 1.20x                  
 *     100            | false   | NONE        | 0.000121                  | 0x                
 *     100            | true    | INCR        | 0.000126                  | 1.04x - slower               
 *     100,000        | true    | DECR        | 0.052810                  | 1.42x                  
 *     100,000        | false   | NONE        | 0.075603                  | 0x               
 *     100,000        | true    | INCR        | 0.058295                  | 1.30x          
 *     200,000        | true    | DECR        | 0.107856                  | 1.33x                  
 *     200,000        | false   | NONE        | 0.143939                  | 0x               
 *     200,000        | true    | INCR        | 0.118558                  | 1.21x    
 *     1,000,000      | true    | DECR        | 0.623353                  | 1.18x                  
 *     1,000,000      | false   | NONE        | 0.736635                  | 0x               
 *     1,000,000      | true    | INCR        | 0.668306                  | 1.10x    
 * 
 * In conclusion, the worst, best and average case senarios are relatively close in running time
 * Notice the best and avarage case times are so close that we can say they are similar in running time.   
*/