#include <stdio.h>
#include <string.h>

char *_getenv(char *name)
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
	return (0);
}
int main()
{
	char s[] = "PATH";
	char *res;
	res = _getenv(s);
	printf ("%s\n", res);
	return (0);
}
