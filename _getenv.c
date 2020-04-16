#include "shell.h"

/**
 * _getenv - gets an environment variable.
 * @name: name of the environment variable.
 * @env: environ.
 * Return: the value of the variable searched.
 */
char *_getenv(const char *name, char **env)
{
	char *comp = NULL;
	int i;

	if (env == NULL)
		return (NULL);

	for (i = 0; env[i]; i++)
	{
		comp = strtok(env[i], "=");
		if (strcmp(comp, name) == 0)
		{
			return (strtok(NULL, "\n"));
		}
	}
	return (NULL);
}
