#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#define TOK_DELIM " \t\r\n\a"

int _strlen(char *s);int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void execute_line(char **arg);
char *read_line(void);
char **split_line(char *line);
