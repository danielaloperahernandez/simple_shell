#include "shell.h"
void built_exit(char *line, char **arg)
{
	free(line);
	free_loop(arg);
	exit(0);
}
void built_env(char **arg, char **env)
{
	char **aux = env;

	while (*aux != NULL)
        {
                printf("%s\n", *aux);
                aux++;
        }
	free_loop(arg);
}
