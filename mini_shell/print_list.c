#include "shell.h"

/**
 * print_list - prints all the elements of a list_t list.
 * If str is NULL, print [0] (nil).
 * @h: pointer to list_t element.
 * Return: the number of nodes.
 */
size_t print_list(const list_p *h)
{
	unsigned int index = 0;

	while (h != NULL)
	{
		if (!h->dir)
			printf("[0] (nil)\n");
		else
			printf("%s\n", h->dir);

		h = h->next;
		index++;
	}

	return (index);
}

