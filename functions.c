#include "main.h"
/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char _c = va_arg(types, int);

	return (handle_write_char(_c, buffer, flags, width, precision, size));
}
/*String Func*/
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int index, l = 0;
	char *p = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (p == NULL)
	{
		p = "(null)";
		if (precision >= 6)
			p = "      ";
	}
	while (p[l] != '\0')
		l++;
	if (precision >= 0 && precision < l)
		l = precision;
	if (width > l)
	{
		if (flags & F_MINUS)
		{
			write(1, &p[0], l);
			for (index = width - l; index > 0; index--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (index = width - l; index > 0; index--)
			{
				write(1, " ", 1);
				index--;
			}
			write(1, &p[0], l);
			return (width);
		}
	}
	return (write(1, p, l));
}
/*Percent Func*/
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}




/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
	{
		buffer[index--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[index--] = (num % 10) + '0';
		num /= 10;
	}
	index++;
	return (write_number(is_negative, index,
			buffer, flags, width, precision, size));
}





/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, index, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	index = 1;
	while (index < 32)
	{
		m /= 2;
		a[index] = (n / m) % 2;
		index++;
	}
	for (index = 0, sum = 0, count = 0; index < 32; index++)
	{
		sum += a[index];
		if (sum || index == 31)
		{
			char z = '0' + a[index];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
