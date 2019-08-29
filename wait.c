#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int hijo;
	int estado;

	hijo = fork();
	if (hijo == -1)
	{
		perror("eoorr:");
		return (1);
	}
	if (hijo == 0)
	{
		printf("wait\n");
		sleep(3);
	}
	else
	{
		wait(&estado);
		printf("oh, its is better\n");
	}
	return (0);
}
