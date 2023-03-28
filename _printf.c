#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;

	int count = 0;

	va_start(args, format);

	for (count = 0; *format; count++)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				break;
			}
			case 's':
			{
				char *s = va_arg(args, char *);

				while (*s)
				{
					write(1, s, 1);
					s++;
				}
				break;
			}
			case '%':
			{
				char c = '%';

				write(1, &c, 1);
				break;
			}
			default:
				break;
			}
		}
		else
		{
			write(1, format, 1);
		}

		format++;
	}

	va_end(args);

	return (count);
}
