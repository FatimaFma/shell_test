#include "main.h"
int open_files(char *f_from, char *f_to);
int read_files(int from_f, int to_f, char *f_from, char *f_to);
int write_to_file(char *buff, int to_f, int read_chars, char *f_to);

/**
 * main - Entry point
 * @argc: Count of the arguments to start the program
 * @argv: An array of strings containing the arguments passed to the program
 * Return: Always zero, but It will have exit 97
 * the file FILE_from, 99 when it can not open/write
 */
int main(int argc, char **argv)
{
	char *f_from;
	char *f_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	f_from = argv[1];
	f_to = argv[2];

	open_files(f_from, f_to);
	exit(0);
	return (0);
}

/**
 * open_files - Opens the files necessary for copying contents
 * @f_from: Name of the file FILE_FROM
 * @f_to: Name of the file FILE_TO
 * Return: Always zero. Exit 98, and 99
 */
int open_files(char *f_from, char *f_to)
{
	int from_f;
	int to_f;

	from_f = open(f_from, O_RDONLY);
	if (from_f == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", f_from);
		exit(98);
	}
	to_f = open(f_to, O_CREAT | O_EXCL | O_WRONLY, 0664);
	if (to_f == -1)
	{
		to_f = open(f_to, O_WRONLY | O_TRUNC);
		if (to_f == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", f_to);
			exit(99);
		}
	}
	read_files(from_f, to_f, f_from, f_to);
	if (close(from_f) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from_f);
		exit(100);
	}
	if (close(to_f) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to_f);
		exit(100);
	}
	return (0);
}
/**
 * read_files - Reads the file FROM_FILE
 * @from_f: File descriptor for FROM_FILE
 * @to_f: File descriptor for TO_FILE
 * @f_from: Name of the file FILE_FROM
 * @f_to: Name of the file FILE_TO
 * Return: Always zero. Exit 98
 */
int read_files(int from_f, int to_f, char *f_from, char *f_to)
{
	int read_chars;
	char buff[1024];

	read_chars = read(from_f, buff, 1024);
	if (read_chars == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", f_from);
		exit(98);
	}
	write_to_file(buff, to_f, read_chars, f_to);
	while (read_chars != 0)
	{
		read_chars = read(from_f, buff, 1024);
		if (read_chars == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", f_from);
			exit(98);
		}
		if (read_chars == 0)
			return (0);
		write_to_file(buff, to_f, read_chars, f_to);
	}
	return (0);
}

/**
 * write_to_file - Writes to a file TO_FILE
 * @buff: array of characters containing up to 1024 chars
 * @to_f: File descriptor of file TO_FILE
 * @read_chars: A number representing how many characters were read and need to
 * be written.
 * @f_to: Name of the file FILE_TO.
 * Return: Always Zero. Exit 99.
 */
int write_to_file(char *buff, int to_f, int read_chars, char *f_to)
{
	int i;

	for (i = 0; i < read_chars; i++)
	{
		if (write(to_f, &buff[i], 1) == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", f_to);
			exit(99);
		}
	}
	return (0);
}
