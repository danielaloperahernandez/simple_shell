#include "shell.h"
#include  <ctype.h>
#include <string.h>
/**
*num_is_positive - function that verify if a string is a positive number
*@com: string to check
*Return: 0 on success and -1 if is negative or is not a number
*/
int num_is_positive(char *com)
{
	int i = 0;

	if (com[0] == '-')
		return (-1);
	for (i = 0; com[i]; i++)
	if (com[i] <= '0' && com[i] >= '9')
		return (-1);
	return (0);
}
/**
*_atoi - transform a char in an integer
*@com: string to check
*Return: the integer
*/
int _atoi(char *com)
{
	int n = 0, sign = 1, result = 0;

	for (n = result = 0; com[n]; n++)
	{
		if (com[n] == '-')
			sign *= -1;
		if (com[n] >= '0' && com[n] <= '9')
			result = 10 * result - (com[n] - '0');
		if (result < 0 && (com[n] < '0' || com[n] > '9'))
			break;
	}
	if (sign > 0)
		result *= -1;
	return (result);
}
/**
*built_exit - function that implement the exit builtin
*@line: the buffer
*@commands: the split arguments
*@exit_st: the exit status
*/
void built_exit(char *line, char **commands, int *exit_st)
{
	int num = 0;

	free(line);
	if (commands[1] && num_is_positive(commands[1]) == 0)
	{
		num = _atoi(commands[1]);
		*exit_st = num;
	}
	else if (num_is_positive(commands[1]) == -1)
	{
		write(1, "Ilegal number\n", 14);
	}
	free_loop(commands);
	exit(*exit_st);
}
/**
*built_env - function that implement the env builtin
*@commands: the split arguments
*@env: the environment
*/
void built_env(char **commands, char **env)
{
	char **aux = env;

	while (*aux != NULL)
	{
		printf("%s\n", *aux);
		aux++;
	}
	free_loop(commands);
}
