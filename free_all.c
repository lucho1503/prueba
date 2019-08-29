#include "holberton.h"

void free_all(char **double_ptr)
{
	unsigned int i;

	i = 0;
	if (double_ptr == NULL)
		return;
	while (double_ptr[i] != NULL)
	{
		free(double_ptr[i]);
		++i;
	}
	if (double_ptr[i] == NULL)
		free(double_ptr[i]);
	free(double_ptr);
}

unsigned int _strlen_const(const char *name)
{
	unsigned int i = 0;

	while (name[i])
		++i;
	return (i);
}
