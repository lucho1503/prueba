#include <stdio.h>
#include <unistd.h>

int main (void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	
	printf ("before excevn\n");
	if (execve(argv[0], argv, NULL) == -1)
		perror("Error");
	printf("despues de excevn\n");
	return (0);
}
