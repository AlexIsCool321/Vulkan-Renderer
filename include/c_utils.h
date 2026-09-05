#ifndef C_UTILS_H
#define C_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>




typedef int bool_t;
#define true	1
#define false	0





#define ADD_ITEM(list, length, item)										\
	do																		\
	{																		\
		void *buffer = realloc(list, sizeof((list)[0]) * ((length) + 1));	\
		if (buffer != NULL)													\
		{																	\
			(list) = buffer;												\
			(list)[length] = (item);										\
			(length)++;														\
		}																	\
	} while (false);




#define CLEAN_FREE(pointer)		\
	do							\
	{							\
		if (pointer != NULL)	\
		{						\
			free (pointer);		\
		}						\
		pointer = NULL;			\
	} while (false);




extern void *Big_Buffer;

void *allocate_big_buffer (int64_t size);
void *allocate_copied_memory (void *memory, uint64_t size);

#endif