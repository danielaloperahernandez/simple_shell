#include "shell.h"
void built_exit(char *line, char **commands)
{
	free(line);
	free_loop(commands);
	exit(0);
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
