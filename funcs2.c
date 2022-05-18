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
	child_pid = fork();
	if (child_pid == 0 && execve(arg[0], arg, NULL) == -1)
	{
		printf("%s: '%s' No such file or directory\n", cmd, arg[0]);
		break;
	}
	else
	wait(&status);
	return (0);
}
