#include "main.h"

/**
 * simple_shell - a beautiful code line
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *av = NULL, *token, *str, *arg[1024], *svptr;
	size_t len = 0, size;
	pid_t my_pid, child_pid;
	int n = 0, err, status;

	if (argc > 1)
	execve(*(argv + 1), (argv + 1), NULL);
	else
	{
		while (1)
		{
			n = 0;
			printf("%s$ ", SHELL_STR);
			size = getline(&av, &len, stdin);
			*(av + size) = '\0';
			token = strtok_r(av, "' \n'", &svptr);
			while (token != NULL)
			{
				str = malloc(sizeof(char) * strlen(token));
				strcpy(str, token);
				*(arg + n) = str;
				token = strtok_r(NULL, "' \n'", &svptr);
				n++;
			}
			*(arg + n) = NULL;

			child_pid = fork();
			if (child_pid == 0)
			{
				n = execve(arg[0], arg, NULL);
				if (n == -1)
				{
					err = errno;
					printf("%s: '%s' No such file or directory\n", argv[0], arg[0]);
				}
				break;
			}
			else
				wait(&status);


			/*n = 0;
			while (*(arg + n) != NULL)
			{
	     			printf("%s\n", *(arg + n));
				n++;
			}*/
		}
	}
	return (0);
}
