#include "shell.h"
/**
*split_line - creates a double pointer array that holders pointers
*to each string from the command line
*@line: buffer that stores the stdin input
*Return: double pointer array of pointers that are commands to interpret
*and execute
*/
char **split_line(char *line)
{
	int j = 0;
	char *token;
	char *token_hash;
	char **word_arr;
	int len;

	len = _strlen(line);

	word_arr = malloc(sizeof(char *) * (len + 1));
	if (word_arr == NULL)
		return (NULL);
	token_hash = strtok(line, "#");
	token = strtok(token_hash, TOK_DELIM);
	while (token != NULL)
	{
		word_arr[j] = malloc(_strlen(token) + 1);
		if (word_arr[j] == NULL)
		{
			free_loop(word_arr);
			return (NULL);
		}
		_strncpy(word_arr[j], token, _strlen(token) + 1);
		token = strtok(NULL, TOK_DELIM);
		j++;
	}
	word_arr[j] = NULL;
	return (word_arr);
}
