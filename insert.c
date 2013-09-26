#include "default.h"
#include "sort.h"


int insert_sort(void** ppvArray, size_t length, DataCompare compare)
{
	int nIndex = 0;
	int nInsert = 0;

	if(ppvArray == NULL || compare == NULL)
	{
		return (ERR_INVALID_PARAM);
	}
	if(length < 2)
	{
		return (ERR_OK);
	}

	for(nIndex = 1; nIndex < length; nIndex++)
	{
		if(compare(ppvArray[nIndex], ppvArray[nIndex - 1]) < 0)
		{
			void* temp = ppvArray[nIndex];
			nInsert = nIndex - 1;
			for(; nInsert >= 0 && compare(temp, ppvArray[nInsert]) < 0; nInsert--)
			{
				ppvArray[nInsert + 1] = ppvArray[nInsert];
			}
			ppvArray[nInsert + 1] = temp;
		}
	}
	return (ERR_OK);
}
