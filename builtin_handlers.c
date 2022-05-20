#include "main.h"
#include <stdio.h>

/**
 *
 * builtin_handlers - a function that

int builtin_handlers(char **cmd, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (_strcmp(*cmd, builtin.env) == 0)
	{
		print_env();
		return (1);
	}
	else if (_strcmp(*cmd, builtin.exit) == 0)
	{
		exit_cmd(cmd, line);
		return (1);
	}
	return (0);
}


void signal_handler(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}


char *find_path(void)
{
	int x;
	char **env = environ, *path = NULL;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && x < 5)
			{
				path++;
				x++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}



void print_env(void)
{
	int x = 0;
	char **env = environ;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], _strlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}


void prompter(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;
	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}
