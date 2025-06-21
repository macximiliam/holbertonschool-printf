#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - simplified version of printf
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	size_t i;

	if (!format)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%' && format[i + 1])
		{
			switch (format[++i])
			{
			case 'c':
				count += print_char(args);
				break;
			case 's':
				count += print_str(args);
				break;
			case '%':
				count += write(1, "%", 1);
				break;
			default:
				count += write(1, "%", 1);
				count += write(1, &format[i], 1);
			}
		}
		else if (format[i] == '%' && !format[i + 1])
		{
			va_end(args);
			return (-1);
		}
		else
			count += write(1, &format[i], 1);
	}
	va_end(args);
	return (count);
}

/**
 * print_char - prints a character
 * @args: list of arguments
 * Return: number of characters printed (1)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_str - prints a string
 * @args: list of arguments
 * Return: number of characters printed
 */
int print_str(va_list args)
{
	char *s = va_arg(args, char *);
	int i, count = 0;

	if (!s)
		s = "(null)";
	for (i = 0; s[i]; i++)
		count += write(1, &s[i], 1);
	return (count);
}
