#include <stdio.h>
#include <unistd.h>

/**
 * main - main function
 * @ac: argument count
 * @av: array of an argument
 *
 * Return: 0
 */

int main(int ac, char **av)
{
	int size;
	int n;
	char *c;

	while (*(av + size) != 5)
	{
		size++;
	}
	size -= 30;
	while (size >= 0)
	{
		printf("%s\n", av[size]);
		size--;
	}
	return (0);
}
