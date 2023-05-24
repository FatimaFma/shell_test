#include "main.h"
/**
 * parsing_cmd -  Parsing commands typed into the shell
 * @buff: The address of the buffer holding command
 * @buff_copy: copy of the buffer holding command
 *
 * Return: array of strings holds commands
 */
char **parsing_cmd(char *buff, char *buff_copy)
{
	const char *s = " \n";
	int token_count = 0;
	char *token;
	int i;
	char **argv;

	token = strtok(buff, s);
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, s);
	}
	token_count++;
	argv = malloc(sizeof(char *) * token_count);
	token = strtok(buff_copy, s);
	if (token == NULL)
		for (i = 1 ; argv[i] != NULL ; i++)
			free(argv[i]);
	for (i = 0; i < token_count - 1; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(argv[i], token);
		token = strtok(NULL, s);
	}
	argv[i] = NULL;
	free(buff_copy);
	return (argv);
}
