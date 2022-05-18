#include "main.h"

/**
 * main - main function
 * @argc: argument count
 * @argv: argument velocity
 * @env: environment
 *
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{

	if (argc > 1)
	execve(*(argv + 1), (argv + 1), NULL);
	else
		shell(argv[0], env);
	return (0);
}

