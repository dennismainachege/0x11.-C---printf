#include "main.h"

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

	for (int i = 0; format[i] != '\0'; i++)
    {
        switch (format[i])
        {
            case '%':
                i++; // Move to the next character after '%'
                switch (format[i])
                {
                    case 'c':
                        {
                            int character = va_arg(extras, int);
                            printf("%c", character);
                            break;
                        }
                    case 's':
                        {
                            char *character_string = va_arg(extras, char *);
                            if (character_string != NULL)
                                printf("%s", character_string);
                            else
                                printf("(null)"); 
                            break;
                        }
                    default:
                        printf("%%");
                        break;
                }
                break;
            default:
                printf("%c", format[i]);
                break;
        }
    }

    va_end(extras);

	return (num_args);
}
