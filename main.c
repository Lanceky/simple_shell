#include "shell.h"

/**
 * main - Entry point for the shell program
 * @argc: Argument count (unused)
 * @argv: Argument vector (used to get the shell name)
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *input;
	int status = 1;

	(void)argc;

	signal(SIGINT, handle_sigint);

	while (status)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		input = read_input();
		if (!input)
			break;

		status = execute_input(input, argv[0]);
		free(input);
	}

	return (EXIT_SUCCESS);
}

