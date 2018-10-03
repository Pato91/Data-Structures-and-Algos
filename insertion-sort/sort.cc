#include "../main.h"

std::vector<int> insertion_sort_asc(std::vector<int>);
std::vector<int> insertion_sort_desc(std::vector<int> input);
std::vector<int> insertion_sort(std::vector<int> input, std::string order = "ASC");
int find_element(std::vector<int> input, int target);

int main(){
    std::vector<int> instance(100000);
    std::generate(instance.begin(), instance.end(), []() -> int {return rand() % 100000;});
    
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> res = insertion_sort(instance);
    auto end = std::chrono::high_resolution_clock::now();
    double v = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    print_to_screen(res);
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



//clang++ -std=c++17 -stdlib=libc++ sort.cpp -o program