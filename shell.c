#include "main.h"

/**
 * simple_shell - a beautiful code line
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	char *av = NULL, *str, *arg[1024], *arg1[1024], *file_path = NULL;
	size_t len = 0, size;
	pid_t my_pid, child_pid;
	int n = 0, err = 0, status, found = 0;
	struct stat st;

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
			found = 0;
			
			str_split(arg, av, "' \n'");
			//free(av);
			
			if (!check_abs(arg[0]))
			{
				err = find_env_var(arg1, env, "PATH");
				if (err >= 0)
				{
					file_path = malloc(1024);
					err = find_file(arg1, arg[0], file_path, st);
					//free(arg[0]);
					if (err != -1)
					{
						arg[0] = file_path;
						found = 1;
					}
					else
					{
						printf("%s: command not found\n", arg[0]);
					}

					
				}
				
			}
			else
			{
				//file_path = arg[0];
				found = 1;
			}
			if (found)
			{
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
			}

			
		}
	}
	return (0);
}

int str_split(char **arg, char *av, char *delmt)
{
	char *token, *svptr, *str;
	int n = 0;
	
	token = strtok_r(av, delmt, &svptr);
	while (token != NULL)
	{
		str = malloc(sizeof(char) * strlen(token));
		strcpy(str, token);
		*(arg + n) = str;
		token = strtok_r(NULL, delmt, &svptr);
		n++;
	}
	*(arg + n) = NULL;
	/*n = 0;
	while (*(arg + n) != NULL)
	{
			printf("%s\n", *(arg + n));
		n++;
	}*/
	return (1);
}

int find_env_var(char **arg, char **env, char *var)
{
	
	char *av;
	int n = 0;
	
	while (env[n] != NULL)
	{
		av = malloc(strlen(env[n]));
		strcpy(av, env[n]);
		str_split(arg, av, "' =:'");
		//free(av);
		if (strcmp(arg[0], var) == 0)
		{
			return (n);
		}
		n++;
	}
	return (-1);
	
}

int check_abs(char *c)
{
	if (*c == '/')
	return (1);
	return (0);
}

int find_file(char **arg, char *f, char *file_path, struct stat st)
{
	int n = 1;
	
	while(arg[n] != NULL)
	{
		strcpy(file_path, arg[n]);
		strcat(file_path, "/");
		strcat(file_path, f);
		if(stat(file_path, &st) == 0)
		{
			return (n);
		}
		n++;
	}
	file_path = NULL;
	return (-1);
}
