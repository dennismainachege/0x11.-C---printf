#include "main.h"

/**
 * _putchar - it writes the character c to stdout
 * @c: The character it will print
 *
 * Return: On success 1
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

