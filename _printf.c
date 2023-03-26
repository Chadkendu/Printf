#include "main.h"
/**
 * printf_buffer - func
 * @buffer: array
 * @buff_ind: index
 */
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf function
 * @format: pointer.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int printed = 0, printed_chars = 0, buffer_index = 0;
	int index, flag, w, s, precision;
	va_list va;
	char buffer[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}
	va_start(va, format);
	index = 0;
	while (format && format[index] != '\0')
	{
		if (format[index] != '%')
		{
			buffer[buffer_index++] = format[index];
			if (buffer_index == BUFF_SIZE)
			{
				print_buffer(buffer, &buffer_index);
			}
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flag = get_flags(format, &index);
			w = get_width(format, &index, va);
			precision = get_precision(format, &index, va);
			s = get_size(format, &index);
			++index;
			printed = handle_print(format, &index, va, buffer,
				flag, w, precision, s);
			if (printed == -1)
			{
				return (-1);
			}
			printed_chars += printed;
		}
		index++;
	}
	print_buffer(buffer, &buffer_index);
	va_end(va);
	return (printed_chars);
}
/**
 * print_buffer - Prints function
 * @buffer: Array
 * @buff_ind: var
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
	}
	*buff_ind = 0;
}
