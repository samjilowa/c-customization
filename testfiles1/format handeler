




====================handel char =============================================

void handle_char(char ch, char *buffer, int *buffer_pos, int *num_chars_printed)
{
	if (*buffer_pos >= 1024)
	{
		write(1, buffer, *buffer_pos);
		*buffer_pos = 0;
	}
	buffer[(*buffer_pos)++] = ch;
	(*num_chars_printed)++;
}

=================handel string ===========================================

void handle_string(char *str, char *buffer, int *buffer_pos, int *num_chars_printed)
{
	int len = strlen(str);
	if (*buffer_pos + len >= 1024)
	{
		write(1, buffer, *buffer_pos);
		*buffer_pos = 0;
	}
	memcpy(buffer + *buffer_pos, str, len);
	*buffer_pos += len;
	(*num_chars_printed) += len;
}
===================handel percent======================================

void handle_percent(char *buffer, int *buffer_pos, int *num_chars_printed)
{
	if (*buffer_pos >= 1024)
	{
		write(1, buffer, *buffer_pos);
		*buffer_pos = 0;
	}
	buffer[(*buffer_pos)++] = '%';
	(*num_chars_printed)++;
}

