#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_char - prints a single character
 * @args: va_list containing the character to print
 * @count: pointer to the character count
 *
 * Return: void
 */
void print_char(va_list args, int *count)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	*count += 1;
}

/**
 * print_string - prints a string
 * @args: va_list containing the string to print
 * @count: pointer to the character count
 *
 * Return: void
 */
void print_string(va_list args, int *count)
{
	char *s = va_arg(args, char *);

	while (*s)
	{
		write(1, s, 1);
		s++;
		*count += 1;
	}
}

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

	 if (!format || (format[0] == '%' && format[1] == '\0'))
                return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				print_char(args, &count);
				break;
			case 's':
				print_string(args, &count);
				break;
			case '%':
				write(1, "%", 1);
				count++;
				break;
			default:
				break;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}

		format++;
	}

	va_end(args);

	return (count);
}
