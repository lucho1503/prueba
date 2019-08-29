#include "holberton.h"

/**
 * _strcmp - entry ponit.
 * @s1:string.
 * @s2:string.
 * Return: diference betwen s1 and s2.
 */

int _strcmp(char *s1, char *s2)
{
	int z = 0;
	for (; *s1 == *s2 && *s1 != 0 && *s2 != 0 ;)
	{
		s1++;
		s2++;
	}
	z = *s1 - *s2;
	return (z);
}

void env_out(char *buf, char **comand, char **env)
{
	free(buf);
	free(*comand);
	free(comand);
	print_env(env);
	exit(EXIT_SUCCESS);
}

void print_env(char **entorno)
{
	unsigned int i = 0, len;
	
	while (entorno[i] != NULL)
	{
		len = strlen(entorno[i]);
		write(STDOUT_FILENO, entorno[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
