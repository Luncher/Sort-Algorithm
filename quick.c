#include "default.h"



static int quick_sort_one(void** ppvArray, int left, int right, DataCompare compare)
{
	int tmp_left = left;
	int tmp_right = right;
	
	if(left < right)
	{
		void* temp = ppvArray[right];
		do
		{
			while(tmp_left < tmp_right && compare(ppvArray[tmp_left], temp) < 0)
			{
				tmp_left++;
			}
			if(tmp_left < tmp_right)
			{
				ppvArray[tmp_right] = ppvArray[tmp_left];
				tmp_right--;
			}
			while(tmp_left < tmp_right && compare(ppvArray[tmp_right], temp) > 0)
			{
				tmp_right--;
			}
			if(tmp_left < tmp_right)
			{
				ppvArray[tmp_left] = ppvArray[tmp_right];
				tmp_left++;
			}	
		}while(tmp_left < tmp_right);

		ppvArray[tmp_left] = temp;
	
		quick_sort_one(ppvArray, left, tmp_left - 1, compare);
		quick_sort_one(ppvArray, tmp_left + 1, right, compare);
	}
	return (ERR_OK);
}


int quick_sort(void** ppvArray, size_t length, DataCompare compare)
{
	if(ppvArray == NULL || compare == NULL)
	{
		return (ERR_INVALID_PARAM);
	}
	if(length < 2)
	{
		return (ERR_OK);
	}
	return (quick_sort_one(ppvArray, 0, length-1, compare));
}


