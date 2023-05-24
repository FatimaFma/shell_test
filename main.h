#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

/* Functions */
char **parsing_cmd(char *buff, char *buff_copy);
void execve_cmd(char **argv);
char *get_path(char *command);
char *_getenv(const char *name);

/* Helper Functions */
char *_strdup(const char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

extern char **environ;

#endif
