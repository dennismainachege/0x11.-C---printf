#include "main.h"

/**
  * _printf - produces output according to a format
  * @format: Character string
  * @...: Extra arguments
  * Return: The number of characters printed
  */
int _printf(const char *format, ...)
{
	unsigned int i;
	unsigned int num_args;
	char character;
	char *character_string;
	va_list extras;

	num_args = strlen(format);
	if (num_args < 1)
		exit(98);

	va_start(extras, format);

	for (i = 0; i < num_args; i++)
	{
		switch (*format++)
		{
			case '%':
				if (format[i + 1] == 'c')
				{
					character = va_arg(extras, int);
					printf("%c", character);
				}

				if (format[i + 1] == 's')
				{
					character_string = va_arg(extras, char *);
					printf("%s", character_string);
				}
		}
	}

	va_end(extras);

	return (num_args);
}
