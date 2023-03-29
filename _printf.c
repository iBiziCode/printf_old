#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_char - prints a single character
 * @args: va_list containing the character to print
 *
 * Return: void
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @args: va_list containing the string to print
 *
 * Return: void
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int len = 0;

	while (*s)
	{
		write(1, s, 1);
		s++;
		len++;
	}

	return (len);
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

	for (; *format; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count += print_char(args);
			else if (*format == 's')
				count += print_string(args);
			else if (*format == '%')
				count += write(1, "%", 1);
			else
			{
				count += write(1, "%", 1);
				count += write(1, format + 1, 1);
			}

		}
		else
		{
			count += write(1, format, 1);
		}

	}

	va_end(args);

	return (count);
}
