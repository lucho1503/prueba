#include "holberton.h"

void error_fork()
{
	perror("Error:");
	exit(EXIT_FAILURE);
}

int _puterror(char c)
{
        return(write(STDERR_FILENO, &c, 1));
}

void error_msg(char **argv, char *com, int i)
{
	int mul, len, copy;

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	copy = i;
	mul = 1;
	len = 1;
	while (copy >= 10)
	{
		copy /= 10;
		mul *= 10;
		++len;
	}
	while (len > 1)
	{
		if ((i / mul) < 10)
		{
			_puterror((i / mul + '0'));
		}
		else
		{
			_puterror((i / mul) % 10 + '0');
		}
		--len;
		mul /= 10;
	}
	_puterror(i % 10 + '0');
      	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, com, _strlen(com));
	write(STDERR_FILENO, ": not found\n", 12);
}

void parent_free(char *buf, char **com)
{
	free(buf);
	free_all(com);
}

void _path(char **com, char *buf, char **env, char **argv, int conteo)
{
	struct stat statbuf_2;
	int i = 0;
	char **dirs;

	dirs = store_environ(com[0], env);
	for (; dirs[i] != '\0'; ++i)
	{
		if (stat(dirs[i], &statbuf_2) == 0)
			execve(dirs[i], com, NULL);
	}
	error_msg(argv, com[0], conteo);
	free(buf);
	free_all(com);
	free_all(dirs);
	exit(EXIT_SUCCESS);
}
