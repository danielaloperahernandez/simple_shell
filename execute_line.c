#include "shell.h"
void execute_line(char **arg)
{
	pid_t pid;
	int status;
	struct stat st;
	char *new_path;
	extern char **environ;

	pid = fork();
	if (pid < 0)
			perror("error fork");
	if (pid == 0)
	{
		if (**arg == '/')
		{
			if ((stat(arg[0], &st)) == 0)
				execve(arg[0], arg, environ);
		}
		else
		{
			new_path = _which(arg);
			if ((stat(new_path, &st)) == 0)
				execve(new_path, arg, environ);
		}
		perror("Error");
		exit(1);
	}
	else
	{
		wait(&status);
		free_loop(arg);
	}
}
