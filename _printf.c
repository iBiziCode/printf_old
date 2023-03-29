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
void print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * print_string - prints a string
 * @args: va_list containing the string to print
 *
 * Return: void
 */
void print_string(va_list args)
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
	int count = 0, i = 0;

	va_start(args, format);

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				count += print_char(va_arg(args, int));
			else if (format[i + 1] == 's')
				count += print_string(va_arg(args, char *));
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
				count += print_int(va_arg(args, int));
			else if (format[i + 1] == '%')
				count += print_char('%');
			else
			{
				print_char('%');
				print_char(format[i + 1]);
				count += 2;
			}
			i++;
		}
		else
		{
			print_char(format[i]);
			count++;
		}
	}

	va_end(args);

	return (count);
}
