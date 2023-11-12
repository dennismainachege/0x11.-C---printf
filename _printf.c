#include "main.h"
#include "for_loop.c"

/**
  * _printf - produces output according to a format
  * @format: Character string
  * @...: Extra arguments
  * Return: The number of characters printed
  */
int _printf(const char *format, ...)
{
	int i;
	int num_args;
	char character;
	char *character_string;
	va_list extras;

	if (format == NULL)
		return (0);

	num_args = strlen(format);
	if (num_args < 1)
		return (0);

	va_start(extras, format);
	#define FOR_LOOP
	va_end(extras);

	return (num_args);
}
