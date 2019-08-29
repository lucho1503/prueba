#include "holberton.h"

unsigned int _strlen(char *s)
{
	unsigned int i = 0;
	for (; *s != 0; s++)
		i++;
	return (i);
}

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

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;
	for (; src[i] != '\0' && i < n; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';
	return (dest);
}

unsigned int largo_del_comando(char *s)
{
	unsigned int commands, i, flag;

	flag = 0;
	commands = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
			flag = 1;

		if ((flag && s[i + 1] == ' ') || (flag && s[i + 1] == '\0'))
		{
			++commands;
			flag = 0;
		}
		++i;
	}
	return (commands);
}

char **_strtok(char *str)
{
	char **tk_hol;
	char *token;
	int i;
	unsigned int len;

	str[_strlen(str) - 1] = '\0';
	len = largo_del_comando(str);
	if (len == 0)
		return (NULL);
        
	tk_hol = malloc((sizeof(char *)) * (len + 1));
	if (tk_hol == NULL)
	{
		return (NULL);
	}
	i = 0;
	token = strtok(str, " ");
	for (; token != NULL; i++)
	{
		tk_hol[i] = malloc(_strlen(token) + 1);
		if (tk_hol[i] == NULL)
		{
			free_all(tk_hol);
			return (NULL);
		}
		_strncpy(tk_hol[i], token, _strlen(token) + 1);
		token = strtok(NULL, " ");
	}
	tk_hol[i] = NULL;
	return (tk_hol);
}
