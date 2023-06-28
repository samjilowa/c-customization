#include "main.h"

int print_b(char *buffer);
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	/*int s = 0;*/
	int num = 0;

	/*printed = 0,*/ 
	int printed_chars = 0;
	/*int flags = 0;
	int width = 0;
	int precisions = 0, size = 0*/
	/*int buff_ind = 0;*/

	va_list list;

	/*char buffer[BUFF_SIZE];*/

	if (format == NULL ||(format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(list, format);

	for (; *format != '\0'; format++)
	{
		if (*format != '%')
		{
			/*buffer[buff_ind++] = format[s];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);*/
			write(1, format, 1);
			printed_chars++;
		}
		else
		{
			format++;

			if (*format == 'c')
			{
				num = va_arg(list, int);
				write(1, &num, 1);
				printed_chars++;
			}
			else if (*format == '%')
			{
				num = 37;
				write(1, &num, 1);
				printed_chars++;
				}
			else if (*format == 's')
                        {
                               printed_chars += print_b(va_arg(list, char*));
                                
                                }

				
			

			/*print_buffer(buffer, &buff_ind);
			flags = flags_sam(format, &s);
			width = width_tigist(format, &s, list);
			precisions = precisions_g(format, &s, list);
			size = size_picker(format, &s);
			++s;

			*printed = handle_print(format, &s, list, buffer,
				flags, width, precisions, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;*/
		}
	}

	/*print_buffer(buffer, &buff_ind);*/

	va_end(list);

	return (printed_chars);
}

/**
 * print_b - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
int print_b(char *buffer)
{
	int length = 0;

	if (buffer == NULL)
		buffer = "(null)";
	while (*buffer != '\0')
	{
		write(1, buffer, 1);
		buffer++;
		length++;

	}
	return (length);
	
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
