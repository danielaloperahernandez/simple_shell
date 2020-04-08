#include "shell.h"
int main(void)
{
	char *line = NULL;
	char **arg;
	size_t bufsize = 0;

	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&line, &bufsize, stdin) == -1)
		{
			write(1, "\n", 1);
			free(line);
			exit(0);
		}
		if (_strcmp(line, "\n") == 0)
			continue;
		arg = split_line(line);
		if (_strcmp("exit", *arg) == 0)
			built_exit(line, arg);
		else if (_strcmp("env", *arg) == 0)
			built_env(arg);
		else
			execute_line(arg);
		fflush(stdin);
	}
	free(line);
	return (0);
}
