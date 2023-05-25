#include "main.h"
int _strcmp(char *str1, char *str2);
int _e_check(char *buff);

/**
 * main - shell main function
 * @ac: number of items in argv
 * @argv: NULL terminated array of strings
 *
 * Return: Always 0.
 */
int main(__attribute__((unused))int ac, char **argv)
{
	char *buff = NULL;
	char *buff_copy = NULL;
	size_t n = 0;
	ssize_t characters;
	int i = 0;

	while (1)
	{
		if (isatty(0))
		{
			write(1, "$cisnotfun ", 11);
		}
		characters = getline(&buff, &n, stdin);
		if (characters == -1)
		{
			write(1, "Exiting shell....\n", 19);
			exit(0);
		}
		if (_e_check(buff))
		{
			continue;
		}
		buff_copy = malloc(sizeof(char) * (characters + 1));
		if (buff_copy == NULL)
		{
			free(buff_copy);
			perror("hsh: Unable to allocate buffer ");
			return (-1);
		}
		_strcpy(buff_copy, buff);
		if (_strcmp(buff_copy, "exit\n") == 0)
		{
			free(buff_copy);
			free(buff);
			if (argv)
			{
				for (i = 0 ; argv[i] ; i++)
					free(argv[i]);
				free(argv);
			}
			exit(0);
			break;
		}
		else
		{
			argv = parsing_cmd(buff, buff_copy);
			if (argv == NULL)
			{
			for (i = 1 ; argv[i] ; i++)
				free(argv[i]);
			}
			execve_cmd(argv);
		}
	}
	free(buff_copy);
	free(buff);
	return (0);
}
/**
 * _strcmp - function that compiare two string
 * @str1: string 1to compare
 * @str2: string 2 to compare
 * Return: 0 if match
 */
int _strcmp(char *str1, char *str2)
{
	unsigned int len, i;

	len = _strlen(str2);
	for (i = 0 ; i < len ; i++)
		if (str1[i] != str2[i])
			return (-1);
	return (0);

}
/**
 * _e_check - check if the the buffer is empty
 * @buff: the buffer to be check
 * Return: 1 if empty, 0 if not
 */
int _e_check(char *buff)
{
	int i = 0;

	if (buff == NULL)
		return (1);
	for (i = 0 ; buff[i] != '\n' && buff[i] != '\0' ; i++)
	{
		if (buff[i] != ' ')
			return (0);
	}
	return (1);
}
