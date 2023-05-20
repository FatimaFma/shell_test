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
	char *lineptr;
	size_t n = 0;
	ssize_t n_chars;

	(void)ac; (void)argv;

	while(1)/* infinite loop to shell */
	{	printf("%s", prompt);
		n_chars = getline(&lineptr, &n, stdin);
		if (n_chars == -1)
		{
			printf("Exiting shell\n");
			return (-1);
		}
		printf("%s\n", lineptr);
		free(lineptr);
	}
	return (0);
}
