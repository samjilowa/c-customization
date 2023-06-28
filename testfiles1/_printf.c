#include"main.h"
#include <unistd.h>
#include <stdarg.h>
#include "format_handeler.c"
#include "handel_converstions_specifires.c"
#include "handel_other_specifires.c"


/**
 *_printf - this functions handle converstion specifires
 *process_conversion_specifier: process asingle conversion specifires
 *Return: characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int num_chars_printed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char ch = va_arg(args, int);
				if (buffer_pos >= 1024)
				{
					write(1, buffer, buffer_pos);
					buffer_pos = 0;
				}
				buffer[buffer_pos++] = ch;
				num_chars_printed++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				int len = strlen(str);
				if (buffer_pos + len >= 1024)
				{
					write(1, buffer, buffer_pos);
					buffer_pos = 0;
				}
				memcpy(buffer + buffer_pos, str, len);
				buffer_pos += len;
				num_chars_printed += len;
			}
			else if (*format == 'd')
			{
				int num = va_arg(args, int);
				HANDLE_INT(num);
			}
			else if (*format == 'u')
			{
				unsigned int num = va_arg(args, unsigned int);
				HANDLE_UNSIGNED(num);
			}
			else if (*format == 'o')
			{
				unsigned int num = va_arg(args, unsigned int);
				HANDLE_OCTAL(num);
			}
			else if (*format == 'x')
			{
				unsigned int num = va_arg(args, unsigned int);
				HANDLE_HEX_LOWER(num);
			}
			else if (*format == 'X')
			{
				unsigned int num = va_arg(args
