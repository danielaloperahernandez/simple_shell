#include "shell.h"
char **split_line(char *line)
{
        int j = 0;
        char *token;
        char ** word_arr = malloc(sizeof(char *));
        if(word_arr == NULL)
                return NULL;
        token = strtok(line, TOK_DELIM);
        while(token != NULL)
        {
                word_arr[j++] = token;
                word_arr = _realloc(word_arr, sizeof(char *) * (j + 1));
		if (word_arr == NULL)
		{
			free_loop(word_arr);
			return NULL;
                }
		token = strtok(NULL, TOK_DELIM);
        }
	word_arr[j] = NULL;
        return word_arr;
}
