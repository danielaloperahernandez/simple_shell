#include "shell.h"

/**
 * _strlen - return length of a string
 * @s: char type
 * Return:  length of string
 */
int _strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 *_strcpy - make
 *@dest: make
 *@src: make
 * Return: return the value dest
 */
char *_strcpy(char *dest, char *src)
{
	int cont;

	for (cont = 0; src[cont] != '\0'; cont++)
	{
		dest[cont] = src[cont];
	}
	dest[cont] = '\0';
	return (dest);
}

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

/**
 * print_list - prints all the elements of a list_p list.
 * If str is NULL, print [0] (nil).
 * @h: pointer to list_p element.
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
/**
 *str_concat - concatenates two strings
 *@s1: point to string
 *@s2: point to string
 *Return: pointer to point a newly allocated
 */
char *str_concat(char *s1, char *s2)
{
	char *cat;
	int i, j, k;

	for (i = 0; s1 && s1[i]; ++i)
		;
	for (j = 0; s2 && s2[j]; ++j)
		;
	cat = (char *)malloc((i + j + 1) * sizeof(char));
	if (cat == NULL)
		return (NULL);
	k = 0;
	for (i = 0; s1 && s1[i]; ++i)
	{
		cat[k] = s1[i];
		++k;
	}
	for (j = 0; s2 && s2[j]; ++j)
	{
		cat[k] = s2[j];
		++k;
	}
	cat[k] = '\0';
	return (cat);
}
