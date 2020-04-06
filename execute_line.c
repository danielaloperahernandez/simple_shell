#include "shell.h"
void execute_line(char **arg, char **env)
{
        pid_t pid;
        int status;
        struct stat st;
	char *new_path;

        pid = fork();
        if (pid < 0)
                perror("error fork");
        if (pid == 0)
        {
		if (**arg == '/')
		{
                	if ((stat(arg[0], &st)) == 0)
				 execve(arg[0], arg, env);
		}
		else
		{
			new_path = _which(arg);
			if ((stat(new_path, &st)) == 0) 
				execve(new_path, arg, env);
		}
		perror("Error");
                exit(1);
        }
        else
        {
                wait(&status);
        }
}
