#include "default.h"
#include "sort.h"


//#define MIN_HEAP_TEST	(1)


#define LEFT_CHILD(parent)	(2*(parent + 1) - 1)
#define RIGHT_CHILD(parent)	(2*(parent + 1))
#define PARENT(child)		((child - 1) / 2)
#define LEAF_START(n)		((n)/2)


static int MinHeapFixUp(void** array, int length, DataCompare compare)
{
	int child  = length;
	int parent = (child - 1) / 2;
	
	for(; parent >= 0; parent = (child - 1)/2)
	{
		if(compare(array[parent], array[child]) > 0)
		{
			void* temp = array[parent];
			array[parent] = array[child];
			array[child]  = temp;
			child = parent;
		}
	}
	return (ERR_OK);
}



int MinHeapInsert(void** array, int length, void* value, DataCompare compare)
{
	if(array == NULL || length < 0)
	{
		return (ERR_INVALID_PARAM);
	}
	array[length] = value;
	return (MinHeapFixUp(array, length, compare));
}



static int MinHeapFixDown(void** array, int length, int parent, DataCompare compare)
{
	void* temp = array[parent];
	int lchild = LEFT_CHILD(parent);

	while(lchild < length)
	{
		if((lchild+1) < length && compare(array[lchild + 1], array[lchild]) < 0)
		{
			lchild += 1;
		}
		if(array[lchild] >= temp)
		{
			break;
		}
		array[parent] = array[lchild];
		parent = lchild;
		lchild = LEFT_CHILD(parent);
	}
	array[parent] = temp;

	return (ERR_OK);
}



int MinHeapDelete(void** array, int length, DataCompare comapre)
{
	if(array == NULL || length <= 0)
	{
		return (ERR_INVALID_PARAM);
	}

	array[0] = array[length - 1];

	return (MinHeapFixDown(array, length - 1, 0, comapre));
}



int MakeMinHeap(void** array, size_t length, DataCompare compare)
{
	int nIndex = 0;
	
	if(array == NULL || length < 1)
	{
		return (ERR_INVALID_PARAM);
	}
	
	for(nIndex = LEAF_START(length) - 1; nIndex >= 0; nIndex--)
	{
		MinHeapFixDown(array, length, nIndex, compare);		
	}
	return (ERR_OK);
}



int MinHeapSort(void** array, size_t length, DataCompare comapre)
{
	int nIndex = 0;
	
	if(array == NULL || length < 1 || comapre == NULL)
	{
		return (ERR_INVALID_PARAM);
	}

	for(nIndex = 1; nIndex < length; nIndex++)
	{
		void* temp = array[0];
		array[0] = array[length - nIndex];
		array[length - nIndex] = temp;

		MinHeapFixDown(array, length - nIndex, 0, comapre);
	}
	return (ERR_OK);
}

#if defined(MIN_HEAP_TEST)

int int_compare(void* data1, void* data2)
{
	return ((int)data1 - (int)data2);
}


int main(void)
{
	int anTest[] = {9,12,17,30,50,20,60,65,4,19};
	int nIndex = 0;

	MakeMinHeap(anTest, sizeof(anTest)/sizeof(anTest[0]), int_compare);

	for(nIndex = 0; nIndex < sizeof(anTest)/sizeof(anTest[0]); nIndex++)
	{
		printf("%d ", anTest[nIndex]);
	}
	printf("\n");
	MinHeapSort(anTest, sizeof(anTest)/sizeof(anTest[0]), int_compare);
	for(nIndex = 0; nIndex < sizeof(anTest)/sizeof(anTest[0]); nIndex++)
	{
		printf("%d ", anTest[nIndex]);
	}
	printf("\n");
}
#endif
