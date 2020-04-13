#include "shell.h"

int print_path()
{
        char *token;
	char *path;

	path = _getenv("PATH");
        token = strtok(path, ":");

        while(token != NULL)
        {
		printf("%s\n", token);
                token = strtok(NULL, ":");
        }
	return (0);
}
