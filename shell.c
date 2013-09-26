#include "default.h"



int shell_sort(void** ppvArray, size_t length, DataCompare compare)
{
	int gap = 0;
	int nIndex = 0;
	

	if(ppvArray == NULL || compare == NULL)
	{
		return (ERR_INVALID_PARAM);
	}
	if(length < 2)
	{
		return (ERR_OK);
	}

	for(gap = length/2; gap > 0; gap/=2)
	{
		for(nIndex = gap; nIndex < length; nIndex++)
		{
			if(compare(ppvArray[nIndex], ppvArray[nIndex - gap]) < 0)
			{
				void* temp = ppvArray[nIndex];
				int nInset = nIndex - gap;
				for(;nInset >= 0 && compare(ppvArray[nInset], temp) > 0; )
				{
					ppvArray[nInset + gap] = ppvArray[nInset];
					nInset-=gap;
				}
				ppvArray[nInset + gap] = temp;
			}
		}
	}
	return (ERR_OK);
}


