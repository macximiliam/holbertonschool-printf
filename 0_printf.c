#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - versión simplificada de printf
 * @format: cadena de formato
 * Return: número de caracteres impresos
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	size_t i, j;
	char *s, c;

	va_start(args, format);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%' && format[i + 1])
		{
			switch (format[++i])
			{
			case 'c':
				c = va_arg(args, int);
				count += write(1, &c, 1);
				break;
			case 's':
				s = va_arg(args, char *);
				if (!s)
					s = "(null)";

				for (j = 0; s[j]; j++)
					count += write(1, &s[j], 1);
				break;
			case '%':
				count += write(1, "%", 1);
				break;
			default:
				count += write(1, "%", 1);
				count += write(1, &format[i], 1);
			}
		}
		else
			count += write(1, &format[i], 1);
	}
	va_end(args);
	return (count);
}
