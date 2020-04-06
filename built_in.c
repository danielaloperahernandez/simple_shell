#include "shell.h"
void built_exit()
{
	exit(0);
}
void built_env(char **env)
{
	char **aux = env;
	while (*aux != NULL)
        {
                printf("%s\n", *aux);
                aux++;
        }
}
