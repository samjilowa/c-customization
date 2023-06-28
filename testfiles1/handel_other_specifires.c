


/*========================handel octal================================================*/

void handle_octal(unsigned int num, char *buffer, int *buffer_pos, int *num_chars_printed)
{
	char *temp = malloc(12 * sizeof(char)); 
	int i = 0;
	if (num == 0) {
		temp[i++] = '0';
	} else {
		while (num > 0) {
			temp[i++] = num % 8 + '0';
			num /= 8;
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
/*=========================handel_unsigned================================================*/

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
/*=======================handel lowercase hexadecimal digit===============================*/


