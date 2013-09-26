#include "sort.h"
#include <assert.h>



static void** dump_creat_sort_array(size_t nCount)  
{  
    int* pnNewArray = malloc(sizeof(int) * nCount);  
    int nIndex = 0;  
  
    for(nIndex = 0; nIndex < nCount; nIndex++)  
    {  
        pnNewArray[nIndex] = rand();  
    }  
//    printf("\n");  
    return ((void**)pnNewArray);  
}  
  
  
static void dump_sort_test(size_t nCount, SortFunc Sortfunc, DataCompare CompareFunc)  
{  
    int nIndex = 0;  
	struct timeval start = {0};
	struct timeval end = {0};
    long long time = 0;
    void **ppvArray = dump_creat_sort_array(nCount);  
    
	gettimeofday(&start, NULL);
    Sortfunc(ppvArray, nCount, CompareFunc);  
	gettimeofday(&end, NULL);

	time = (end.tv_sec - start.tv_sec)*1000000 + end.tv_usec - start.tv_usec;	
  
    for(nIndex = 1; nIndex < nCount; nIndex++)  
    {  
        assert(ppvArray[nIndex - 1] <= ppvArray[nIndex]);  
    }  
    printf("测试通过.");  
    printf("排序%d个元素, 耗时:%lldus\n\n", nCount, time);
    free(ppvArray);  
    ppvArray = NULL;  
}  
  
  
void dump_sort(int nTimes, SortFunc Sortfunc, DataCompare CompareFunc)  
{  
    int nIndex = 0;  
  
    if(nTimes > 0)  
    {  
        dump_sort_test(nTimes, Sortfunc, CompareFunc);  
    }  
}  



void show_array(int* array, int size)
{
	int nIndex = 0;

	for(nIndex = 0; nIndex < size; nIndex++)
	{
		printf("%d ",array[nIndex]);
	}
	printf("\n");
}



int int_compare(void* data1, void* data2)
{
	return ((int)data1 - (int)data2);
}

#define TEST_SIZE	(60000)


int main()
{
	int test[][10] = {
		{6,4,1,0,3,7,8,9,5,2},
		{63,43,121,60,73,37,28,19,52,21},
		{96,94,71,60,32,73,84,95,56,62},
		{66,49,31,40,43,73,81,92,53,25},
		{62,14,21,20,43,37,856,964,53,2},	
		{61,24,19,63,35,70,88,97,56,72},
		{6,34,14,30,3,7,82,94,56,26}
	};
	
	printf("#test bubble sort\n");	
	dump_sort(TEST_SIZE, bubble_sort, int_compare);

	printf("#test insert sort\n");	
	dump_sort(TEST_SIZE, insert_sort, int_compare);

	printf("#test select sort\n");	
	dump_sort(TEST_SIZE, select_sort, int_compare);

	printf("#test shell sort\n");	
	dump_sort(TEST_SIZE, shell_sort, int_compare);

	printf("#test merge sort\n");	
	dump_sort(TEST_SIZE, merge_sort, int_compare);

	printf("#test quick sort\n");	
	dump_sort(TEST_SIZE, quick_sort, int_compare);

	printf("#test min heap sort\n");	
	printf("source array:");
	show_array(test[0], 10);
	MakeMinHeap((void**)test[0], 10, int_compare);
	MinHeapSort((void**)test[0], 10, int_compare);
	printf("dest   array:");
	show_array(test[0], 10);
	printf("\n");
}
