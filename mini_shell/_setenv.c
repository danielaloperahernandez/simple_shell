#include "shell.h"
int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	int len_name, len_val, i;
	char *new_val = NULL;

	if (_getenv(name) && overwrite == 0)
		return (0);
	
	len_name = _strlen((char *)name);                           
	len_val = _strlen((char *)value);

	if (_getenv(name) == NULL)
	{
		for(i = 0; environ[i]; i++)
			;
		environ[i] = malloc(len_name + len_val + 2);
		if (environ[i] == NULL)
			return (-1);
		new_val = str_concat((char *)name, "=");
		new_val = str_concat(new_val, (char *)value);
		environ[i] = new_val;
		printf("%s", environ[i]);
	}
	return(0);
}
int main()
{
	/*const char name[] = "PATH";*/
	const char value[] = "hola";
	extern char **environ;
	char **environ2 = environ;
	while (*environ2 != NULL)
        {
                printf("%s\n", *environ2);
                environ2++;
        }
        _setenv("PATH", value, 1);
	putchar('\n');
	return (0);
}
