#include "main.h"
/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: Name of the file
 * @text_content: String to append at the end of a file
 * Return: 1 if the file exist, -1 if the file is Null
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int f;
	int i;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
		return (1);
	f = open(filename, O_APPEND | O_WRONLY);
	if (f == -1)
		return (-1);
	for (i = 0; text_content[i] != '\0'; i++)
	{
		if (write(f, &text_content[i], 1) == -1)
		{
			close(f);
			return (-1);
		}
	}
	close(f);
	return (1);
}
