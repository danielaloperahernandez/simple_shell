#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#define TOK_DELIM " \t\r\n\a"
typedef struct list_path
{
        char *dir;
        struct list_path *next;
} list_p;
int _strlen(char *s);int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void execute_line(char **arg);
char *read_line(void);
char **split_line(char *line);
char *_getenv(char *name);
list_p *add_node_end(list_p **head, const char *str);
size_t print_list(const list_p *h);
