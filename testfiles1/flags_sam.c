#include "main.h"

/**
 * flags_sam - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 *Authours:Samuel jilowa and Tigist Paulos
 */
int flags_sam(const char *format, int *r)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int m, curr_r;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_r = *r + 1; format[curr_r] != '\0'; curr_r++)
	{
		for (m = 0; FLAGS_CH[m] != '\0'; m++)
			if (format[curr_r] == FLAGS_CH[m])
			{
				flags |= FLAGS_ARR[m];
				break;
			}

		if (FLAGS_CH[m] == 0)
			break;
	}

	*r = curr_r - 1;

	return (flags);
}
