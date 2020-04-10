#include "shell.h"
void execute_line(char **argv, char **commands, int count)
{
	pid_t pid;
	int status;
	char *full_path;
	extern char **environ;

	pid = fork();
	if (pid < 0)
		perror("Error:");
	if (pid == 0)
	{
		full_path = commands[0];
		if (**commands != '/')
			full_path = _which(commands);

		if (access(full_path, X_OK) == 0)
		{
			execve(full_path, commands, environ);
		}
		_error(argv, commands[0], count);
		exit(1);
	}
	else
	{
		wait(&status);
		free_loop(commands);
	}
}
