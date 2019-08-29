#include "holberton.h"

char *_strncpycmd(char *dest, char *src, char* com, int n, int c)
{
	int i, j;

	i = 0, j = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
		dest[i] = '/';
		i++;
	}
	while (j < c && *com != '\0')
	{
		dest[i] = com[j];
		i++; j++;
		dest[i] = '\0';
	}
	return (dest);
}

char *_strncpyconst(char *dest, const char *src, int n)
{
	int i = 0;

	while (i < n && *src != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void com_null(char* buf)
{
	free(buf);
	exit(EXIT_SUCCESS);
}

void exit_out(char *buf, char **com)
{
	free(buf);
	free_all(com);
	exit(EXIT_SUCCESS);
}

void env_out(char *buf, char** com, char **env)
{
	free(buf);
	free_all(com);
	print_env(env);
	exit(EXIT_SUCCESS);
}
