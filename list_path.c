#include "shell.h"
/**
 *add_node_end - append node to list pointed
 *@head: pointer to pointer
 *@dir: string to initialize new node
 *Return: new or NULL
 */
void add_node_end(list_p **head, const char *dir)
{
	list_p *last = *head;
	list_p *new = malloc(sizeof(list_p));

	new->next = NULL;
	new->dir = _strdup((char *)dir);
	if (last)
	{
		while (last->next)
		last = last->next;
		last->next = new;
	}
	else
		*head = new;
}
/**
 *list_path - function that builds a linked list of the PATH directories
 *@env: environment variables
 *Return: the head of the list
 */
list_p *list_path(char **env)
{
	char *token;
	char *path;
	list_p *head;

	head = NULL;
	path = _getenv("PATH", env);
	add_node_end(&head, ".");
	token = strtok(path, ":");
	while (token != NULL)
	{
		add_node_end(&head, token);
		token = strtok(NULL, ":");
	}
	return (head);
}
