#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	if (argc != 2)
	{
		fprintf(stderr, "use: %s <file<\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		printf("line of length %zu:\n", nread);
		fwrite(line, nread, 1, stdout);
	}
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
} 
