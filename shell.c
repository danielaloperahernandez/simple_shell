#include "shell.h"
int main(void)
{
	char *line = NULL;
	char **arg;
	size_t bufsize = 0;
	int line_len = 0;

	while (1)
	{
		if (isatty(fileno(stdin)))
			write(1, "#cisfun$ ", 9);
		line_len = getline(&line, &bufsize, stdin);
		if (line_len == -1 && isatty(fileno(stdin)))
		{
			write(1, "\n", 1);
			free(line);
			exit(0);
		}
                if (line_len == -1 && !isatty(fileno(stdin)))
		{
			free(line);
			exit(0);
		}
		if (_strcmp(line, "\n") == 0)
			continue;
		arg = split_line(line);
		if (!*arg)
			continue;
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
