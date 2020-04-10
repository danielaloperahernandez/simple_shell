#include "shell.h"
void execute_line(char **argv, char **commands, int count)
{
	pid_t pid;
	int status;
	struct stat st;
	char *new_path;
	extern char **environ;

	pid = fork();
	if (pid < 0)
			perror("Error:");
	if (pid == 0)
	{
		if (**commands == '/')
		{
			if ((stat(commands[0], &st)) == 0)
				execve(commands[0], commands, environ);
		}
		else
		{
			new_path = _which(commands);
			if ((stat(new_path, &st)) == 0)
				execve(new_path, commands, environ);
		}
		no_found(argv, commands[0], count);
		exit(1);
	}
	else
	{
		wait(&status);
		free_loop(commands);
	}
}
