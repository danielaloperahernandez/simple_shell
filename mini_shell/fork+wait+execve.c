#include "shell.h"
void execute_line(char **arg)
{
        pid_t pid;
        int status;
        struct stat st;

        pid = fork();
        if (pid < 0)
                perror("error fork");
        if (pid == 0)
        {
                if ((stat(arg[0], &st)) == 0)
                {
                        execve(arg[0], arg, NULL);
                        perror("Error");
                        return;
                }
                else
                {
			perror("Error");
                        return;
                }
        }
        else
        {
                wait(&status);
        }
}
