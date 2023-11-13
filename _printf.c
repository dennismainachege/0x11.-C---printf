#include "main.h"

/**
  * _printf - produces output according to a format
  * @format: Character string
  * @...: Extra arguments
  * Return: The number of characters printed
  */
int _printf(const char *format, ...)
{
	int num_args;
	int num_of_characters_printed;
	va_list extras;

	if (format == NULL)
		return (0);

	num_args = strlen(format);
	if (num_args < 1)
		return (0);

	va_start(extras, format);

	num_of_characters_printed = conversion_handler(format, extras);
	va_end(extras);

	return (num_of_characters_printed);
}

int conversion_handler(const char *format, va_list extras)
{
	int i;

	int count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		switch (format[i])
		{
			case '%':
				i++; /* Move to the next character after '%' */
				switch (format[i])
				{
					case 'c':
					{
						int character = va_arg(extras, int);

						printf("%c", character);
						break;
					}
					case 'i':
					{
						int num_i = va_arg(extras, int);

						printf("%i", num_i);
						break;
					}
					case 'd':
					{
						int num_d = va_arg(extras, int);

						printf("%d", num_d);
						break;
					}
					case 'u':
					{
						unsigned int num_u = va_arg(extras, int);

						printf("%u", num_u);
						break;
					}
					case 'o':
					{
						unsigned int num_o = va_arg(extras, int);

						printf("%o", num_o);
						break;
					}
					case 'x':
					{
						unsigned int num_x = va_arg(extras, int);

						printf("%x", num_x);
						break;
					}
					case 'X':
					{
						unsigned int num_X = va_arg(extras, int);

						printf("%X", num_X);
						break;
					}
					case 'p':
					{
						void *addr = va_arg(extras, void *);

						printf("%p", addr);
						break;
					}
					case '%':
					{
						count++;
						putchar('%');
						break;
					}
					case 's':
					{
						char *character_string = va_arg(extras, char *);

						if (character_string != NULL)
						{
							printf("%s", character_string);
						}
						else
						{
							printf("(null)");
						}
						break;
					}
					default:
					{
						putchar('%');
						printf("%c", format[i]);
						break;
					}
				}
				break;
			default:
				putchar(format[i]);
				count++;
				break;
		}
	}
	return (count);
}
