#include "shell.h"
void built_exit(char *line, char **arg)
{
	free(line);
	free_loop(arg);
	exit(0);
}
void built_env(char **arg)
{
	extern char **environ;
	char **aux = environ;

	while (*aux != NULL)
        {
                printf("%s\n", *aux);
                aux++;
        }
	free_loop(arg);
}
