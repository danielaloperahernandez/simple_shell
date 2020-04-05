#include "shell.h"

void find_file_in_path(list_p *head, char *file)
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
}

int main(int argc, char *argv[])
{
	list_p *head;
	int count = 1;
	(void)argc;
	(void)argv;

	head = list_path();

	while (argv[count])
	{
		find_file_in_path(head, argv[count]);
		count++;
	}

	free(head);
	return (0);
}
