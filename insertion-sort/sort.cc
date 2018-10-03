#include "../main.h"

std::vector<int> insertion_sort_asc(std::vector<int>);
std::vector<int> insertion_sort_desc(std::vector<int> input);
std::vector<int> insertion_sort(std::vector<int> input, std::string order = "ASC");
int find_element(std::vector<int> input, int target);

int main(){
    std::vector<int> instance(100);
    std::generate(instance.begin(), instance.end(), []() -> int {return rand() % 100;});
    
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

std::vector<int> insertion_sort(std::vector<int> input, std::string order){
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