#include "default.h"


int select_sort(void** array, size_t length, DataCompare compare)
{
	int nIndex = 0;
	int nSwap = 0;
	int nMax = 0;

	if(array == NULL || length < 1 || compare == NULL)
	{
		return (ERR_INVALID_PARAM);
	}	
	
	for(nIndex = length - 1; nIndex > 0; nIndex--)
	{
		nMax = nIndex;
		for(nSwap = 0; nSwap < nIndex; nSwap++)
		{
			if(compare(array[nSwap], array[nMax]) > 0)
			{
				nMax = nSwap;
			}
		}
		if(nMax != nIndex)
		{
			void* temp = array[nIndex];
			array[nIndex] = array[nMax];
			array[nMax] = temp;
		}
	}
	return (ERR_OK);
}
