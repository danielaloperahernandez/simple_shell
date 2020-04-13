#include "shell.h"
/**
*_execute - function that executes in the main shell
*@argv: argument char-pointers array
*@commands: split arguments
*@count: count of commands that were run
*@env: the environment
*@exit_st: exit status
*/
void execute_line(char **argv, char **commands, int count,
char **env, int *exit_st)
{
	pid_t pid;
	int status;
	char *full_path;

	pid = fork();
	if (pid < 0)
		perror("Error:");
	if (pid == 0)
	{
		full_path = commands[0];
		if (**commands != '/')
			full_path = _which(commands, env);

		if (access(full_path, X_OK) == 0)
		{
			execve(full_path, commands, env);
		}
		_error(argv, commands[0], count, &exit_st);
		exit(*exit_st);
	}
	else
	{
		wait(&status);
		*exit_st = WEXITSTATUS(status);
		free_loop(commands);
	}
}
