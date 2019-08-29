#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int input(char *s, int len);

int main()
{
	char* buf;
	size_t sizebuf = 32;
	ssize_t ch;
	char *pesos = "$ ";
	
	buf = malloc(sizebuf * sizeof(char));
	if (buf == NULL)
	{
		perror("unable");
		exit(1);
	}
	if (isatty(STDIN_FILENO))
	    {
		    write(STDOUT_FILENO, pesos, 2);
	    }

	
	while(ch = getline(&buf, &sizebuf, stdin))
	{
		if (ch == 0)
		{
			perror("error");
		}
		printf("%s", buf);
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, pesos, 2);
		}
	}
	
	return 0;
}
