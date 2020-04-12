#include "shell.h"
int special_case(char *line, ssize_t line_len, int *exit_st)
{
        if (line_len == -1 && isatty(fileno(stdin)))
        {
                write(1, "\n", 1);
                free(line);
                exit(*exit_st);
        }
        if (line_len == -1 && !isatty(fileno(stdin)))
        {
                free(line);
                exit(*exit_st);
        }
        if (_strcmp(line, "\n") == 0)
        {
                *exit_st = 0;
		return(3);
        }
        return (0);
}
