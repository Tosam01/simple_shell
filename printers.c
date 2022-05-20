#include "main.h"

/**
 * _putchar - putchar function
 * @c: value
 * Return: 1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_s - print function
 * @s: value
 * Return: i
 */

int print_s(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}

	return (i);
}
