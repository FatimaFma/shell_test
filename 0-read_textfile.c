#include "main.h"
/**
 * read_textfile - Reads a file and prints it to the POSIX stdout
 * @filename: name of the file that needs to be read
 * @letters: Is the number of letters the function should print
 * Return: actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int f;
	int i;
	int r;
	char *buf;

	if (filename == NULL)
		return (0);
	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);
	f = open(filename, O_RDONLY);
	if (f == -1)
	{
		free(buf);
		return (0);
	}

	r = read(f, buf, letters);
	if (r == -1)
	{
		close(f);
		free(buf);
		return (0);
	}

	for (i = 0; i < r; i++)
	{
		if (write(STDOUT_FILENO, &buf[i], 1) == -1)
		{
			close(f);
			free(buf);
			return (0);
		}

	}
	close(f);
	free(buf);
	return (r);
}
