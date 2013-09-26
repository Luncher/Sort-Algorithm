#include <limits.h>
#include "default.h"
#include "sort.h"



static int merge_sort_one(void** ppvArray, int left, int right, DataCompare compare)
{
	int nIndex = 0;
	int nIndex2 = 0;
	int mid = (left + right)/2;
	int nLen1 = (mid - left) + 1;
	int nLen2 = (right - mid);
	void** pvLeft = NULL; 
	void** pvRight = NULL;
	
	if(left < right)
	{
		merge_sort_one(ppvArray, left, mid, compare);
		merge_sort_one(ppvArray, mid+1, right, compare);

		pvLeft = (void**)malloc(sizeof(void*) * (nLen1 + 1));
		pvRight = (void**)malloc(sizeof(void*) * (nLen2 + 1));
		for(nIndex = 0; nIndex < nLen1; nIndex++)
		{
			pvLeft[nIndex] = ppvArray[nIndex + left];
		}
		pvLeft[nIndex] = (void*)INT_MAX;
		
		for(nIndex = 0; nIndex < nLen2; nIndex++)
		{
			pvRight[nIndex] = ppvArray[nIndex + mid + 1];
		}
		pvRight[nIndex] = (void*)INT_MAX;

		nIndex = 0;
		nIndex2 = 0;
		while(left <= right)
		{
			if(compare(pvLeft[nIndex], pvRight[nIndex2]) > 0)
			{
				ppvArray[left] = pvRight[nIndex2];
				++nIndex2;
			}
			else
			{
				ppvArray[left] = pvLeft[nIndex];
				++nIndex;
			}
			++left;
		}
		free(pvLeft);
		free(pvRight);

		return (ERR_OK);
	}
	return (ERR_FAIL);
}


int merge_sort(void** ppvArray, size_t length, DataCompare compare)
{
	if(ppvArray == NULL || compare == NULL)
	{
		return (ERR_FAIL);
	}
	if(length < 2)
	{
		return (ERR_OK);
	}
	return (merge_sort_one(ppvArray, 0, length-1, compare));
}

