#include "shell.h"
int main(void)
{
	char *line;
	char **arg;

	line = read_line();
	arg = split_line(line);
	execute_line(arg);
	free (line);
	free(arg);
	return (0);
}
