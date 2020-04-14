#include "shell.h"
/**
*free_loop - function for free double pointer array of pointers
*@arr: double pointer array of pointers
*/
void free_loop(char **arr)
{
	int len;

	for (len = 0; arr[len]; len++)
		free(arr[len]);
	free(arr);
}

/**
 *free_list - frees a listint_t list
 *@head: head of a listint_t list
 */
void free_list(list_p *head)
{
	list_p *prev;

	while (head)
	{
		free(head->dir);
		prev = head;
		head = head->next;
		free(prev);
	}
}
