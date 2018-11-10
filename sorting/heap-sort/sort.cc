#include "./sort.h"

int main(){
    std::vector<int> instance(10);
    std::generate(instance.begin(), instance.end(), []() -> int {return rand() % 10;});
    Heap heap;
    heap.list = instance;
    auto start = std::chrono::high_resolution_clock::now();
    heap_sort(&heap);
    // merge_sort(instance.begin(), instance.end(), std::greater<> {}); // decending
    auto end = std::chrono::high_resolution_clock::now();
    double v = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    print_to_screen(heap.list);
    printf("\n\n");
    printf("\n\n\nTook %f seconds to execute\n\n\n", v/1000000);

}