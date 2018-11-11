#ifndef _MAIN_DEFINITIONS_
#define _MAIN_DEFINITIONS_

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
#include <stdlib.h>
#include <regex>
#include <functional>
#include <iterator>
#include <tuple>
#include <limits>
#include <cmath>
#include <benchmark/benchmark.h>

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

void print_to_screen(std::vector<int> v){
    for(int i : v){
        printf("%d\n", i);
    }
}

std::string get_current_working_directory( void ) {
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
}

std::string to_lower(std::string s){
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){
        return std::tolower(c);
    });
    return s;
}

void generate_rand_values(std::vector<int> * range, const int rand_max){
    std::generate(range->begin(), range->end(), [&rand_max]() -> int { return rand() % rand_max;});
}

static void BM_algos(benchmark::State& state){
    
}

BENCHMARK(BM_algos);

#endif