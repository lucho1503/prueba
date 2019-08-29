#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv [])
{
	pid_t pid;
	int n = atoi(argv[1]);
	int i;

	for (i = 0; i < n; i++)
	{
		pid = fork();
		printf("padre %d --------- creo hijo %d\n", getpid(), pid);
	}
	
	exit (0);
}
