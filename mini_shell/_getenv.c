#include "shell.h"
#include <stdio.h>
#include <string.h>

char *_getenv(const char *name)
{
	extern char **environ;
	char *comp = NULL;
	int i;

	for (i = 0; environ[i]; i++)
	{
		comp = strtok(environ[i], "=");
		if (strcmp(comp, name) == 0)
		{
			return (strtok(NULL, "\n"));
		}
	}
	return (NULL);
}
