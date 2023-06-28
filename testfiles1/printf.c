#include <unistd.h>
#include <stdarg.h>

/**
 *_printf - this functions handle converstion specifires
 *output_char: writes a single character to standard output
 *@c:the character to write
 *output_string: write anull terminated string
 *output_unrecognized: writes unrecognized conversions specifires
 *process_conversion_specifier: process asingle conversion specifires
 *Return: characters
 */

int output_char(int c)
{
	return (write(1, &c, 1));
}

int output_string(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (write(1, str, len));
}

int output_unrecognized(char c)
{
	char temp_str[2];

	temp_str[0] = '%';
	temp_str[1] = c;
	return (write(1, temp_str, 2));
}

int process_conversion_specifier(const char *format, va_list args)
{
	int count = 0;

	switch (*format)
	{
		case 'c':
			count += output_char(va_arg(args, int));
			break;

		case 's':
			count += output_string(va_arg(args, char *));
			break;

		case '%':
			count += output_char('%');
			break;

		default:
			count += output_unrecognized(*format);
			break;
	}

	return (count);
}

int _printf(const char *format, ...)
{
	int count = 0;

	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += process_conversion_specifier(format, args);
		}
		else
		{
			count += output_char(*format);
		}

		format++;
	}

	va_end(args);

	return (count);
}

