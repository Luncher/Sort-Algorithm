#ifndef _DEFAULT_H_
#define _DEFAULT_H_

#include <stdio.h>
#include <stdlib.h>


#define RET_IF_FAIL(p)	if(!(p))	\
	{printf("Warning:%s.%d. "#p" failed.\n", __func__, __LINE__); return;};

#define RET_VAL_IF_FAIL(p, val)		if(!(p))	\
	{printf("Warning:%s.%d. "#p" failed.\n", __func__, __LINE__); return(val);};



typedef enum tagERR_E
{
	ERR_OK = 0,
	ERR_FAIL = -1,
	ERR_INVALID_PARAM,
	ERR_OOM
}ERR_E;

typedef int(*DataCompare)(void* pvData1, void* pvData2);

typedef int (*SortFunc)(void** data, size_t length, DataCompare compare);




#endif//_DEFAULT_H_


