#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define TOK_DELIM " \t\r\n"

/**
 * struct list_p - singly linked list
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

void execute_line(char **argv, char **commands, int count);
char **split_line(char *line);
char *_getenv(const char *name);
list_p *list_path();
int _setenv(const char *name, const char *value, int overwrite);
char *_which(char *arg[]);
void built_exit(char *line, char **arg);
void built_env(char **arg);
void no_found(char **argv, char *first, int count);
/**
 * useful functions
 */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
list_p *add_node_end(list_p **head, const char *str);
size_t print_list(const list_p *h);
char *_strcat(char *s1, char *s2);
char *_strdup(char *str);
char **_realloc(char **ptr, size_t size);
int _strcmp(char *s1, char *s2);
void free_loop(char **arr);
char *_strncpy(char *dest, char *src, int n);
