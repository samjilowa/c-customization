#include "main.h"

/**
 * precisions_g - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precisions.
 *
*int precisions_g(const char *format, int *r, va_list list)
{
	int curr_r = *r + 1;
	int precisions = -1;

	if (format[curr_r] != '.')
		return (precisions);

	precisions = 0;

	for (curr_r += 1; format[curr_r] != '\0'; curr_r++)
	{
		if (is_digit(format[curr_r]))
		{
			precisions *= 10;
			precisions += format[curr_r] - '0';
		}
		else if (format[curr_r] == '*')
		{
			curr_r++;
			precisions = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*r = curr_r - 1;

	return (precisions);
}*/
