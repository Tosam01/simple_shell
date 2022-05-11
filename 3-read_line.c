#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	char *c = NULL;
	size_t len = 0;

	printf("$ ");
	getline(&c, &len, stdin);
	printf("%s", c);
	return (0);
}
