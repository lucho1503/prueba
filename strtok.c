#include <stdio.h>
#include <string.h>

char *strt(char *str)
{
	int size = strlen(str);
	char del[] = " ";
	char *ptr = strtok(str, del);
	
	while (ptr)
	{
		
		ptr = strtok(NULL, del);
	}
	return (ptr);
}
