#include "shell.h"
int main(int argc, char **argv)
{
	char *line = NULL;
	char **commands;
	size_t bufsize = 0;
	ssize_t line_len = 0, count = 0;
	int exit_st;
	(void)argc;
	
	while (1)
	{
		if (isatty(fileno(stdin)))
			write(1, "($) ", 4);
		line_len = getline(&line, &bufsize, stdin);
		count++;
		if (special_case(line, line_len, &exit_st) == 3)
			continue;
		commands = split_line(line);
		if (!*commands)
			continue;
		if (_strcmp("exit", *commands) == 0)
			built_exit(line, commands, &exit_st);
		else if (_strcmp("env", *commands) == 0)
			built_env(commands);
		else
			execute_line(argv, commands, count, &exit_st);
		fflush(stdin);
	}
	free(line);
	return (0);
}
