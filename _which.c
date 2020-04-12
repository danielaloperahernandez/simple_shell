#include "shell.h"
/**
*_which - fuction that looks for files in the current PATH.
*@commands:the split arguments
*Return: full_path of the command or NULL if it can´t find it
*/
char *_which(char **commands)
{
	list_p *head;
	char *full_path = NULL;
	struct stat st;

	head = list_path();
	while (head)
	{
		full_path = _strcat(head->dir, "/");
		full_path = _strcat(full_path, commands[0]);

		if (stat(full_path, &st) == 0)
			break;
		head = head->next;
	}
	if (full_path == NULL)
	{
		perror("");
		return (NULL);
	}
	return (full_path);
}
