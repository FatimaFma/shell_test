#include "main.h"
/**
 * create_file - Function that creates a file
 * @filename: name of the file to create
 * @text_content: string to write to the file
 * Return: 1 on success, -1 on fail
 */
int create_file(const char *filename, char *text_content)
{
	int f;
	int i;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
		text_content = "";

	f = open(filename, O_CREAT | O_EXCL | O_WRONLY, 0600);
	if (f < 0)
	{
		if (errno == EEXIST)
		{
			f = open(filename, O_WRONLY | O_TRUNC);
			if (f == -1)
				return (-1);
		}
		else
			return (-1);
	}
	for (i = 0; text_content[i] != '\0'; i++)
	{
		if (write(f, &text_content[i], 1) == -1)
			return (-1);
	}
	close(f);
	return (1);
}
