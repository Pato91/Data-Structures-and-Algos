#ifndef _HEAP_SORT_DEFINITIONS_
#define _HEAP_SORT_DEFINITIONS_

#include "../../main.h"

namespace CustomHeap{
    #define parentOf(index) (index - 1) / 2
    #define left(index) 2 * index
    #define right(index) (2 * index) + 1
    class IntegerHeap{

        int heap_size = 0;
        std::vector<int> * heap;

        public:
        IntegerHeap(std::vector<int> * list): heap(list){}

        void max_heapify(int index){
            int largest;
            int left_index = left(index);
            int right_index = right(index);

            if(left_index <= this->heap_size && this->heap->at(left_index) > this->heap->at(index))
                largest = left_index;
            else
                largest = index;
            
            if(right_index <= this->heap_size && this->heap->at(right_index) > this->heap->at(largest))
                largest = right_index;

            if(largest != index){
                std::iter_swap(&this->heap->at(index), &this->heap->at(largest));
                max_heapify(largest);
            }
        }

        void build_max_heap(){
            this->heap_size = this->heap->size() - 1;
            for(int i = std::floor((this->heap->size() - 1) / 2); i >= 0; --i){
                this->max_heapify(i);
            }
        }

        void heap_sort(){
            this->build_max_heap();
            for(int i = (this->heap->size() - 1); i >= 1; --i){
                std::iter_swap(&this->heap->at(0), &this->heap->at(i));
                this->heap_size -= 1;
                this->max_heapify(0);
            }
        }
    };
}

#endif