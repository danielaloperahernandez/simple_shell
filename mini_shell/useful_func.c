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
#include "shell.h"
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

