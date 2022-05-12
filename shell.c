#include "main.h"

/**
 * simple_shell - a beautiful code line
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *av = NULL, *token, *str, *arg[20], *svptr;
	size_t len = 0, size;
	int n = 0;

	if (argc > 1)
	execve(*(argv + 1), (argv + 1), NULL);
	else
	{

		
		size = getline(&av, &len, stdin);
		*(av + size) = '\0';
		token = strtok_r(av, " ", &svptr);
		while (1);
		{
			//str = malloc(sizeof(char) * strlen(token));
			//strcpy(str, token);
			printf("gets here\n");
			*(arg + n) = token;

			token = strtok_r(NULL, " ", &svptr);
			if (token == NULL)
				break;
			n++;
			printf("loop\n");
		}

	}
	*(arg + n) = NULL;
	n = 0;
	while (*(arg + n) != NULL)
	{
	       printf("%s\n", *(arg + n));
	       n++;
	}
	return (0);
}
