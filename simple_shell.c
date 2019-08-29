#include "holberton.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void INThandler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}

int main(int argc __attribute__((unused)), char **argv, char **env)
{
	char *env_com = "env", *pesos = "$ ", *exit_com = "exit";
	pid_t hijo; struct stat statbuf;
	char **com; char *buf;
	size_t len; ssize_t ch;
	int status, i;

	buf = NULL, len = 0, i = 0;
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, pesos, 2);
	}
	signal(SIGINT, INThandler);
	while((ch = getline(&buf, &len, stdin) != -1))
	{
		if (ch == EOF)
		{
			eof(buf);
		}		
		++i;
		com = _strtok(buf);
		hijo = fork();
		if (hijo == -1)
			error_fork();
		if (hijo == 0)
		{
		        if (com == NULL)
				com_null(buf);
			else if (_strcmp(exit_com, com[0]))
				exit_out(buf, com);
			else if (_strcmp(env_com, com[0]))
				env_out(buf, com, env);
			else if (stat(com[0], &statbuf))
				execve(com[0], com, NULL);
			else
				_path(com, buf, env, argv, i);
		}
		else
		{
			wait(&status);
			if (com == NULL)
				parent_free(buf, com);
			else if (_strcmp(exit_com, com[0]))
				exit_out(buf, com);
			else
				parent_free(buf,com);
		}
		len = 0; buf = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, pesos, 2);
	}
	if (ch == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
