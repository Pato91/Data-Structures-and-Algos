#ifndef _HEAP_SORT_DEFINITIONS_
#define _HEAP_SORT_DEFINITIONS_

#include "../../main.h"

#define parentOf(index) (index - 1) / 2
#define left(index) 2 * index
#define right(index) (2 * index) + 1


struct Heap {
    int heap_size = 0;
    std::vector<int> list;
};

void max_heapify(Heap * heap, int index){
    int largest;
    int left_index = left(index);
    int right_index = right(index);

    if(left_index <= heap->heap_size && heap->list.at(left_index) > heap->list.at(index))
        largest = left_index;
    else
        largest = index;
    
    if(right_index <= heap->heap_size && heap->list.at(right_index) > heap->list.at(index))
        largest = right_index;

    if(largest != index){
        std::iter_swap(&heap->list.at(index), &heap->list.at(largest));
        max_heapify(heap, largest);
    }
}

void build_max_heap(Heap * heap){
    heap->heap_size = heap->list.size() - 1;
    for(int i = heap->list.size(); i > -1; --i){
        max_heapify(heap, i);
    }
}

void heap_sort(Heap * heap){
    build_max_heap(heap);
    for(int i = (heap->list.size() - 1); i > 0; --i){
        std::iter_swap(&heap->list.at(0), &heap->list.at(i));
        heap->heap_size -= 1;
        max_heapify(heap, 0);
    }
}

#endif