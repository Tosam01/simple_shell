#include "main.h"


char *appender(char *path, char *cmd)
{
	char *buffer;
	size_t n = 0, m = 0;

	if (cmd == 0)
		cmd = "";

	if (path == 0)
		path = "";

	buffer = malloc(sizeof(char) * (_strlen(path) + _strlen(cmd) + 2));
	if (!buffer)
		return (NULL);

	while (path[n])
	{
		buffer[n] = path[n];
		n++;
	}

	if (path[n - 1] != '/')
	{
		buffer[n] = '/';
		n++;
	}
	while (cmd[m])
	{
		buffer[n + m] = cmd[m];
		m++;
	}
	buffer[n + m] = '\0';
	return (buffer);
}

int checker(char **cmd, char *buffer)
{
	if (builtin_handlers(cmd, buffer))
		return (1);
	else if (**cmd == '/')
	{
		execute(cmd[0], cmd);
		return (1);
	}
	return (0);
}

void execute(char *cp, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cp);
	if (child_pid == 0)
	{
		execve(cp, cmd, env);
		perror(cp);
		free(cp);
		free2(cmd);
		exit(98);
	}
	else
		wait(&status);
}

void exit_cmd(char **cmd, char *line)
{
	free(line);
	free2(cmd);
	exit(0);
}

void free2(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}