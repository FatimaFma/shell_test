#include "main.h"

/**
 * execve_cmd - function to execute the command.
 * @argv: array of strings holds commands
 */
void execve_cmd(char **argv)
{
	char *command = NULL;
	char *real_command = NULL;
	int pid;

	if (argv)
	{
		command = argv[0];
		real_command = get_path(command);
		if (real_command == NULL)
			free (real_command);
		if (real_command != NULL)
		{
			pid = fork();
			if (pid == 0)
			{
				if (execve(real_command, argv, NULL) == -1)
				{
					free(argv);
					perror("Error");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(NULL);
			}
		}
	}
}
