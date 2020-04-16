#include "shell.h"
/**
*_werror - puts a char to the std error
*@c: character to write
*Return: int to print
*/
int _werror(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}
/**
*print_num - function that print a num with function write
*@count: the number of times you have done a command
*/
void print_num(int count)
{
	int nlen = 1, powten = 1, count2;

	count2 = count;

	while (count2 >= 10)
	{
		count2 /= 10;
		powten *= 10;
		++nlen;
	}
	while (nlen >= 1)
	{
		if ((count / powten) < 10)
			_werror(count / powten + '0');
		else
			_werror(((count / powten) % 10 + '0'));
		--nlen;
		powten /= 10;
	}
}
/**
*_error - writes an error message similar to the sh error
*when command not found
*@argv: the argv from the main function
*@first: first command to print if not found
*@count: the number of times you have done a command
*@exit_st: exit status
*/
void _error(char **argv, char *first, int count, int **exit_st)
{
	struct stat st;

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ":", 2);
	print_num(count);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, first, _strlen(first));
	write(STDERR_FILENO, ": ", 2);
	if (stat(first, &st) == 0 && S_ISDIR(st.st_mode))
	{
		**exit_st = 126;
		if (_strcmp(first, "..") == 0)
			**exit_st = 127;
		perror("");
	}
	else
	{
		**exit_st = 127;
		write(STDERR_FILENO, "not found\n", 10);
	}
}
