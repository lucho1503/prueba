#include <stdio.h>
#include <unistd.h>

/**
 * main - PPID
 *
 * Return: Always 0.
 */

int main (void)
{
	printf("%u\n", getppid());
	return (0);
}
