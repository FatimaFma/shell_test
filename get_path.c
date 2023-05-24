#include "main.h"

/**
 * get_path - function gets the path for the given command
 * @command: The given command
 * Return: The path for the given command
 */
char *get_path(char *command)
{
	char *path;
	char *path_copy;
	int len;
	char *path_token;
	int dir_len;
	char *fpath;
	struct stat buffer;

	path = _getenv("PATH");
	if (path)
	{
		path_copy = _strdup(path);
		len = _strlen(command);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			dir_len = _strlen(path_token);
			fpath = malloc(len + dir_len + 2);
			_strcpy(fpath, path_token);
			_strcat(fpath, "/");
			_strcat(fpath, command);
			_strcat(fpath, "\0");
			if (stat(fpath, &buffer) == 0)
			{
				free(path_copy);
				return (fpath);
			}
			else
			{
				free(fpath);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}
