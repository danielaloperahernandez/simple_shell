#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define TOK_DELIM " \t\r\n\v\a"
/**
* struct list_path - singly linked list
* @dir: string - (malloc'ed string)
* @next: points to the next node
*
* Description: singly linked list node structure
* for directories of PATH
*/
typedef struct list_path
{
	char *dir;
	struct list_path *next;
} list_p;

/*Functions of the shell*/
void execute_line(char **argv, char **commands, int count,
		  char **env, int *exit_st, char *line);
char **split_line(char *line);
list_p *list_path(char **env);
int _setenv(const char *name, const char *value, int overwrite);
char *_which(char **commands, char **env);
void built_exit(char *line, char **arg, int *exit_st, int count);
void built_env(char **arg, char **env, int *exit_st);
char *_getenv(const char *name, char **env);
void _error(char **argv, char *first, int count, int **exit_st);
int special_case(char *line, ssize_t line_len, int *exit_st);
void print_num(int count);

/*useful functions*/
int _strlen(char *s);
void add_node_end(list_p **head, const char *str);
char *_strcat(char *s1, char *s2);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
void free_loop(char **arr);
void free_list(list_p *head);
char *_strncpy(char *dest, char *src, int n);
#endif /* SHELL_H*/
