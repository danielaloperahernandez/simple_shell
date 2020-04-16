#include "shell.h"
#include <ctype.h>
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
	{
		if (com[i] < 48 || com[i] > 57)
			return (-1);
	}
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
*@count: count of lines
*/
void built_exit(char *line, char **commands, int *exit_st, int count)
{
	int num = 0;

	if (commands[1])
	{
		if (num_is_positive(commands[1]) == 0)
		{
			num = _atoi(commands[1]);
			*exit_st = num;
		}
		else
		{
			write(1, "./hsh: ", 7);
			print_num(count);
			write(1, ": ", 2);
			write(1, "exit: Illegal number: ", 22);
			write(1, commands[1], _strlen(commands[1]));
			write(1, "\n", 1);
			*exit_st = 2;
			free_loop(commands);
			return;
		}
	}
	free_loop(commands);
	free(line);
	exit(*exit_st);
}
/**
*built_env - function that implement the env builtin
*@commands: the split arguments
*@env: the environment
*@exit_st: the exit status
*/
void built_env(char **commands, char **env, int *exit_st)
{
	char **aux = env;

	while (*aux != NULL)
	{
		write(1, *aux, _strlen(*aux));
		write(1, "\n", 1);
		aux++;
	}
	*exit_st = 0;
	free_loop(commands);
}
