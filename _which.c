#include "shell.h"

char *find_file_in_path(list_p *head, char *file)
{
        struct stat st;
        char *full_path = NULL;

	while(head)
	{
		full_path = str_concat(head->dir, "/");
		full_path = str_concat(full_path, file);

		if (stat(full_path, &st) == 0)
		{
			printf("%s\n", full_path);
		}

		head = head->next;
	}

	return (full_path);
}

char *_which(char *arg[])
{
	list_p *head;
	char *full_path;

	head = list_path();
	full_path = find_file_in_path(head, arg[0]);

	if (full_path == NULL)
	{
		perror("");
		return (NULL);
	}
	/*free(head);*/
	return (full_path);
}
