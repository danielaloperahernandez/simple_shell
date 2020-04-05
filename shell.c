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
			break;
		}
		arg = split_line(line);
		execute_line(arg);
		/*free (line);*/
		/*for (len = 0; arg[len]; len++)
			arg[len];
			free(arg);*/
		/*fflush(stdin);*/
	}

	return (0);
}
