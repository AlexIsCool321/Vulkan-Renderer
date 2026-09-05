#include "c_utils.h"

void *Big_Buffer = NULL;

void *allocate_big_buffer (int64_t size)
{
	if (size == 0)
	{
		CLEAN_FREE (Big_Buffer);
		return NULL;
	}

	void *buffer = realloc(Big_Buffer, size);
	if (buffer == NULL) { return NULL; }

	Big_Buffer = buffer;

	return buffer;
}

void *allocate_copied_memory (void *memory, uint64_t size)
{
	if (memory == NULL)	{ return NULL; }
	if (size == 0)		{ return NULL; }

	void *buffer = malloc(size);
	if (buffer == NULL) { return NULL; }

	memcpy (buffer, memory, size);

	return buffer;
}