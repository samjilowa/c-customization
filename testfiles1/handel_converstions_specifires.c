


/*================handel converstions specifiers=========================*/

void handle_conversion_specifier(char specifier, va_list args, char *buffer, int *buffer_pos, int *num_chars_printed)
{
        switch (specifier) {
                case 'd':
                case 'i':
                        {
                                int num = va_arg(args, int);
                                handle_decimal(num, buffer, buffer_pos, num_chars_printed);
                        }
                        break;
                default:

                        break;
        }
}
/*================handels binary===========================================*/

void handle_binary(unsigned int num, char *buffer, int *buffer_pos, int *num_chars_printed)
{
        char *temp = malloc(33 * sizeof(char));
        int i = 0;

        do {
                temp[i++] = "01"[num & 1];
        } while (num >>= 1);
        reverse(temp, i);
        int len = strlen(temp);
        if (*buffer_pos + len >= 1024)
        {
                write(1, buffer, *buffer_pos);
                *buffer_pos = 0;
        }
        memcpy(buffer + *buffer_pos, temp, len);
        *buffer_pos += len;
        (*num_chars_printed) += len;
        free(temp);

/*==================handel converstion specifires1=========================*/

void handle_unsigned(unsigned int num, char *buffer, int *buffer_pos, int *num_chars_printed)
{
        char *temp = malloc(12 * sizeof(char));
        int i = 0;
        if (num == 0) {
                temp[i++] = '0';
        } else {
                while (num > 0) {
                        temp[i++] = num % 10 + '0';
                        num /= 10;
                }
                reverse(temp, i);
        }
        int len = strlen(temp);
        if (*buffer_pos + len >= 1024)
        {
                write(1, buffer, *buffer_pos);
                *buffer_pos = 0;
        }
        memcpy(buffer + *buffer_pos, temp, len);
        *buffer_pos += len;
        (*num_chars_printed) += len;
        free(temp);
}
