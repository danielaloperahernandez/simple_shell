#include "shell.h"
/**
*_which - fuction that looks for files in the current PATH.
*@commands:the split arguments
*@env: environment variables.
*Return: full_path of the command or NULL if it can´t find it
*/
char *_which(char **commands, char **env)
{
	list_p *head;
	list_p *aux;
	char *first_part = NULL;
	char *full_path = NULL;
	char *final_path = NULL;
	struct stat st;

	head = list_path(env);
	aux = head;
	while (aux)
	{
		first_part = _strcat(aux->dir, "/");
		full_path = _strcat(first_part, commands[0]);
		free(first_part);
		if (stat(full_path, &st) == 0)
		{
			final_path = full_path;
			break;
		}
		free(full_path);
		aux = aux->next;
	}
	free_list(head);
	return (final_path);
}
