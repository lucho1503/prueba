#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void INThandler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$", 3);
}

int main(int argc, char **av, char **env)
{
	char *cmd [] = {"ls", (char *) 0};
	int ret;
	size_t len;
	ssize_t ch;
	pid_t pid;
	char *buf; char **comand;
	char* pesos = "$ ", *va_entorno = "env";
	

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, pesos, 2);
	
	signal(SIGINT, INThandler);
	while ((ch = getline(&buf, &len, stdin)))
	{
		if (ch == EOF)
                {
                        write(STDOUT_FILENO, "\n", 1);
                        exit(0);
		}
		
		ch = strt(buf);
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (fork == 0)
		{
		
		
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, pesos, 2);
		}
	        
	}
	if (ch == -1)
		return (EXIT_FAILURE);
	return(EXIT_SUCCESS);
}
