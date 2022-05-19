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
	int status, n, prev = 0, next = 0;

	while (1)
	{
		next = check_next(arg, prev);
		if (next > 0)
		{
			free(*(arg + next));
			*(arg + next) = NULL;
		}
		
		child_pid = fork();
		if (child_pid == 0 && execve(arg[prev], arg[prev], NULL) == -1)
		{
			printf("%s: '%s' No such file or directory\n", cmd, arg[prev]);
			return (-1);
		}
		else
		wait(&status);
		if (next == 0)
			break;
		prev = next++;
	}
	return (0);
}


/**
 * check_next - execute function
 * @arg: command to execute
 * @prev: command to execute
 *
 * Return: 0
 */
int check_next(char **arg, int *prev)
{
	int next;

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
