#include "shell.h"
/**
*built_exit - function that implement the exit builtin
*@line: the buffer
*@commands: the split arguments
*@exit_st: the exit status
*/
void built_exit(char *line, char **commands, int *exit_st)
{
	free(line);
	free_loop(commands);
	exit(*exit_st);
}
/**
*built_env - function that implement the env builtin
*@commands: the split arguments
*@env: the environment
*/
void built_env(char **commands, char **env)
{
	char **aux = env;

	while (*aux != NULL)
	{
		printf("%s\n", *aux);
		aux++;
	}
	free_loop(commands);
}
