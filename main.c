#include "main.h"
/**
 * main - fuction that contain prompt and print
 * @ac: lenth of array
 * @av: array
 * Return: 0
 */
int main(int ac, char **argv)
{
	char *prompt = "(Eshell) $";
	char *lineptr = NULL;
	char *lineptr_c = NULL;
	const char *delim = " \n";
	size_t n = 0;
	ssize_t n_chars;
	int num_token = 0;
	char *token;
	int i;

	(void)ac;

	while (1)/* infinite loop to shell */
	{	printf("%s", prompt);
		n_chars = getline(&lineptr, &n, stdin);
		if (n_chars == -1)
		{
			printf("Exiting shell\n");
			return (-1);
		}

		lineptr_c = malloc(sizeof(char) * n_chars);
		if (lineptr_c == NULL)
		{
			perror("tsh, merory allocation error");
			return (-1);
		}

		strcpy(lineptr_c, lineptr);
		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			num_token++;
			token = strtok(NULL, delim);
		}
		num_token++;

		argv = malloc(sizeof(char *) * num_token);
		token = strtok(lineptr_c, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		execmd(argv);
	}
	free(lineptr_c);
	free(lineptr);
	return (0);
}
