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
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
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

	for (; *format; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count += print_char(args);
			else if (*format == 's')
				print_string(args, &count);
			else if (*format == '%')
				write(1, "%", 1);
			else
				write(1, "r", 1);
		}
		else
		{
			write(1, format, 1);
			count++;
		}
	}

	va_end(args);

	return (count);
}
