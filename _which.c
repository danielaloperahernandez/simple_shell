#include "shell.h"
char *_which(char *arg[])
{
	list_p *head;
	char *full_path = NULL;
	struct stat st;

	head = list_path();
	while(head)
        {
                full_path = str_concat(head->dir, "/");
                full_path = str_concat(full_path, arg[0]);

                if (stat(full_path, &st) == 0)
                        break;
                head = head->next;
        }
	if (full_path == NULL)
	{
		perror("");
		return (NULL);
	}
	/*free(head);*/
	return (full_path);
}
