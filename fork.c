#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int my_pid;
	int pid;

	printf("antes de fork\n");
	pid = fork();
	if (pid == -1)
	{
		perror("error:");
		return (1);
	}
	printf("despues del fork\n");
	my_pid = getpid();
	printf("my pid is %d\n", my_pid);
	return (0);
}
