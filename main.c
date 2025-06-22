#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	printf("Return value: _printf = %d | printf = %d\n", len, len2);

	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');

	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");

	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	printf("Return value: _printf = %d | printf = %d\n", len, len2);

	 _printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);

	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);

	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);

	return (0);
}
