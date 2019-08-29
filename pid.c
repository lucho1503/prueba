#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;

	my_pid = fork();
	printf("%u\n", my_pid);
	exit(0);
}
