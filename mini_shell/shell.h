#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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

void execute_line(char **arg);
char *read_line(void);
char **split_line(char *line);
char *_getenv(char *name);

/**
 * useful_func
 */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
list_p *add_node_end(list_p **head, const char *str);
size_t print_list(const list_p *h);
