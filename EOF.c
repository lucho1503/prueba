#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	int fd[2];
	char buf[100];
	int num;

	pipe(fd);
	
	switch(fork())
	{
	case 0:
		
		write(fd[1], "abcd ...\0", 9);
		write(fd[1], "ijky ........", 9);
		wait(5);
		close(fd[1]);
		exit(0);
		break;
		
	case -1:
		break;
	default:
		close(fd[1]);
		while(0 < (num = read(fd[0], buf, sizeof(buf))))
		{
			buf[num] = 0;
			printf("el padre recibe %d bytes, %s \n", num, buf);
		}
		printf("el padre temrino.........\n");
		close(fd[0]);
		break;
	}
}
