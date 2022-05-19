#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * main - main function
 * @ac: arguument count
 * @av: array of an argument
 *
 * Return: 0
 */

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
