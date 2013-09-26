#include "default.h"

int bubble_sort(void** ppvArray, size_t length, DataCompare compare)
{
	int nKey = 0;
	int nSwap = 0;
	int nIndex = length;

	if(ppvArray == NULL || compare == NULL  || length < 1)
	{
		return (ERR_INVALID_PARAM);
	}
	if(length < 2)
	{
		return (ERR_OK);
	}
	while(nIndex > 1)	
	{
		for(nSwap = 0; nSwap < nIndex - 1; nSwap++)
		{
			if(compare(ppvArray[nSwap], ppvArray[nSwap + 1]) > 0)
			{
				void* temp = ppvArray[nSwap];
				ppvArray[nSwap] = ppvArray[nSwap + 1];
				ppvArray[nSwap + 1] = temp;
				nKey = nSwap + 1;
			}
		}
		nIndex = (nKey < nIndex -1 ? nKey:nIndex - 1);
	}
	return (ERR_OK);
}

