#ifndef _SORT_H_
#define _SORT_H_

#include "default.h"

int bubble_sort(void** ppvArray, size_t length, DataCompare compare);


int select_sort(void** ppvArray, size_t length, DataCompare compare);


int insert_sort(void** ppvArray, size_t length, DataCompare compare);


int shell_sort(void** ppvArray, size_t length, DataCompare compare);


int quick_sort(void** ppvArray, size_t length, DataCompare compare);


int merge_sort(void** ppvArray, size_t length, DataCompare compare);


int MinHeapInsert(void** array, int length, void* value, DataCompare compare);


int MinHeapDelete(void** array, int length, DataCompare comapre);


int MakeMinHeap(void** array, size_t length, DataCompare compare);


int MinHeapSort(void** array, size_t length, DataCompare comapre);


#endif//_SORT_H_
