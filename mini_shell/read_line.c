#include "shell.h"
char *read_line(void)
{
        char *line = NULL;
        size_t bufsize = 0;

        printf("#cisfun$ ");
        getline(&line, &bufsize, stdin);
        return (line);
}
