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
