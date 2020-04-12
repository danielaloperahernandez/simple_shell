#include "shell.h"
void built_exit(char *line, char **commands, int *exit_st)
{
	free(line);
	free_loop(commands);
	exit(*exit_st);
}
void built_env(char **commands)
{
	extern char **environ;
	char **aux = environ;

	while (*aux != NULL)
        {
                printf("%s\n", *aux);
                aux++;
        }
	free_loop(commands);
}
