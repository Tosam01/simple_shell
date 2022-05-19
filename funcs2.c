#include "main.h"


/**
 * execute - execute function
 * @cmd: command to execute
 * @arg: command to execute
 *
 * Return: 0
 */
int execute(char *cmd, char **arg)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0 && execve(arg[0], arg, NULL) == -1)
	{
		printf("%s: '%s' No such file or directory\n", cmd, arg[0]);
		return (-1);
	}
	else
	wait(&status);
	return (0);
}


/**
 * check_next - execute function
 * @arg: command to execute
 * @prev: command to execute
 *
 * Return: 0
 */
int check_next(char **arg, int prev)
{
	if (prev > 0)
		prev++;
	while (*(arg + prev) != NULL)
	{
		if (strcmp("next", *(arg + prev)) == 0)
			return (prev);
		prev++;
	}
	return (0);
}



int free2(char **arg)
{
	int n = 0;

	while (*(arg + n) != NULL)
	{
		free(*(arg + n));
	}
	return (0);
}
