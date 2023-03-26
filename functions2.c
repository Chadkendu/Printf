#include "main.h"
/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int index = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);
	if (addrs == NULL)
	{
		return (write(1, "(nil)", 5));
	}
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	num_addrs = (unsigned long)addrs;
	while (num_addrs > 0)
	{
		buffer[index--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
	{
		padd = '0';
	}
	if (flags & F_PLUS)
	{
		extra_c = '+', length++;
	}
	else if (flags & F_SPACE)
	{
		extra_c = ' ', length++;
	}
	index++;
	return (write_pointer(buffer, index, length,
				width, flags, padd, extra_c, padd_start));
}
/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int index = 0, offset = 0;
	char *p = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (p == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (p[index] != '\0')
	{
		if (is_printable(p[index]))
		{
			buffer[index + offset] = p[index];
		}
		else
		{
			offset += append_hexa_code(p[index], buffer, index + offset);
		}
		index++;
	}
	buffer[index + offset] = '\0';
	return (write(1, buffer, index + offset));
}
/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *p;
	int index, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	p = va_arg(types, char *);

	if (p == NULL)
	{
		UNUSED(precision);
		p = ")Null(";
	}
	for (index = 0; p[index]; index++)
		;

	for (index = index - 1; index >= 0; index--)
	{
		char z = p[index];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *p;
	unsigned int index, index2;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	p = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (p == NULL)
	{
		p = "(AHYY)";
	}
	for (index = 0; p[index]; index++)
	{
		for (index = 0; in[index2]; index2++)
		{
			if (in[index2] == p[index])
			{
				x = out[index2];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[index2])
		{
			x = p[index];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
