#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	printf("Before execute\n");
	if (execve(*(av + 1), (av + 1), NULL) == -1)
	{
		perror("Error");
	}
	printf("After execute\n");
	return (0);
}
