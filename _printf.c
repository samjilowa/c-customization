#include "main.h"

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...)
{
    if (format == NULL)
        return -1;

    int printed_chars = 0;
    va_list list;
    va_start(list, format);

    char buffer[BUFF_SIZE];
    int buff_ind = 0;

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
            {
                print_buffer(buffer, &buff_ind);
                printed_chars += buff_ind;
            }
        }
        else
        {
            print_buffer(buffer, &buff_ind);
            i++; // Skip the '%'

            // Handle format specifiers
            int flags = get_flags(format, &i);
            int width = get_width(format, &i, list);
            int precision = get_precision(format, &i, list);
            int size = get_size(format, &i);

            int printed = handle_print(format, &i, list, buffer, flags, width, precision, size);
            if (printed == -1)
            {
                va_end(list);
                return -1;
            }
            printed_chars += printed;
        }
    }

    print_buffer(buffer, &buff_ind);
    va_end(list);

    return printed_chars;
}

void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
        write(1, buffer, *buff_ind);
    *buff_ind = 0;
}
