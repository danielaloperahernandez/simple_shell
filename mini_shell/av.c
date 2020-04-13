#include <stdio.h>
int main(int argc, char **argv)
{
	(void)argc;
	
	while (*argv != NULL)
	{
		while (**argv != '\0') 
		{
			putchar(**argv);
			++(*argv);
		}
		putchar('\n');
		++argv;
	}
	return (0);
}
