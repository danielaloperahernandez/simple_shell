#include "shell.h"

list_p *list_path()
{
        char *token;
	char *path;
	list_p *head;

	head = NULL;
	path = _getenv("PATH");
        token = strtok(path, ":");

        while(token != NULL)
        {
		add_node_end(&head, token);
                token = strtok(NULL, ":");
        }

	return (head);
}
