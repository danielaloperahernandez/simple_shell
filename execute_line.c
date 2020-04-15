#include "shell.h"
/**
*_execute - function that executes in the main shell
*@argv: argument char-pointers array
*@commands: split arguments
*@count: count of commands that were run
*@env: the environment
*@exit_st: exit status
*@line: buffer of getline
*/
void execute_line(char **argv, char **commands, int count,
		  char **env, int *exit_st, char *line)
{
	pid_t pid;
	int status;
	char *full_path = NULL;
	(void)line;
	pid = fork();
	if (pid < 0)
		perror("Error:");
	if (pid == 0)
	{
		full_path = commands[0];
		if (**commands != '/' && _strcmp(commands[0], "..") != 0)
			full_path = _which(commands, env);
		if (full_path)
		{
			if (access(full_path, X_OK) == 0)
				execve(full_path, commands, env);
		}
		_error(argv, commands[0], count, &exit_st);
		free_loop(commands);
		free(line);
		exit(*exit_st);
	}
	else
	{
		wait(&status);
		free_loop(commands);
		*exit_st = WEXITSTATUS(status);
	}
}
