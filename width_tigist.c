#include "main.h"

/**
 * width_tigist - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int width_tigist(const char *format, int *r, va_list list)
{
	int curr_r;
	int width = 0;

	for (curr_r = *r + 1; format[curr_r] != '\0'; curr_r++)
	{
		if (is_digit(format[curr_r]))
		{
			width *= 10;
			width += format[curr_r] - '0';
		}
		else if (format[curr_r] == '*')
		{
			curr_r++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*r = curr_r - 1;

	return (width);
}
