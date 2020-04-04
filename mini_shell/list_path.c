#include "shell.h"

int print_path()
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
	print_list(head);
	return (0);
}
int main(void)
{
	print_path();
	return (0);
}
