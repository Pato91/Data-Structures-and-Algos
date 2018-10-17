#include "./search.h"

int main(){
    std::vector<int> instance(100);
    std::generate(instance.begin(), instance.end(), []() -> int {return rand() % 100;});
    merge_sort(instance.begin(), instance.end());
    auto start = std::chrono::high_resolution_clock::now();
    int res = binary_search(&instance, instance.at(52), instance.size());
    auto end = std::chrono::high_resolution_clock::now();
    double v = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    printf("%d", res);
    printf("\n\n");
    printf("\n\n\nTook %f seconds to execute\n\n\n", v/1000000);
    return 0;
}
