#include "shell.h"
#include <string.h>
/**
*add_node_end - append node to list pointed
*@head: pointer to pointer
*@str: string to initialize new node
*Return: new or NULL
*/
list_p *add_node_end(list_p **head, const char *dir)
{
	list_p *last = *head;
	list_p *new = malloc(sizeof(list_p));

	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->dir = strdup(dir);
	if (last)
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*head = new;
	return (new);
}
