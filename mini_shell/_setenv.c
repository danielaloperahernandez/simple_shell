#include "shell.h"
int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	int len_name, len_val, i, cont, cont2;
	/*char *new_val = NULL;*/

	if (_getenv(name) && overwrite == 0)
		return (0);
	
	for (len_name = 0; name[len_name]; len_name++)
		;
	for (len_val = 0; value[len_val]; len_val++)
		;
	if (_getenv(name) == NULL)
	{
		for(i = 0; environ[i]; i++)
			;
		environ[i] = malloc(len_name + len_val + 2);
		if (environ[i] == NULL)
			return (-1);
		for (cont = 0; name[cont]; cont++)
			environ[i][cont] = name[cont];
		environ[i][cont] = '=';
		cont++;
		for (cont2 = 0; value[cont2]; cont2++)
			environ[i][cont + cont2] = value[cont2];
		environ[i][cont + cont2] = '\0';
		printf("%s", environ[i]);
	}
	return(0);
}
int main()
{
	const char name[] = "PATH";
	const char value[] = "hola";
	extern char **environ;
	char **environ2 = environ;
	while (*environ2 != NULL)
        {
                printf("%s\n", *environ2);
                environ2++;
        }
        _setenv(name, value, 1);
	putchar('\n');
	while (*environ != NULL)
        {
                printf("%s\n", *environ);
                environ++;
        }
	return (0);
}
