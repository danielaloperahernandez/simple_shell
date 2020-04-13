#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv, char **env)
{
	extern char **environ;
	(void)argc;
	(void)argv;
	(void)env;

	while (*environ != NULL)
	{
		printf("%s\n", *environ);
		environ++;
	}
	return (0);
}
