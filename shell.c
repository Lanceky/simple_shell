#include "shell.h"

/**
*main - Entry point of the shell
*@argc: Argument count
*@argv: Argument vector
*Return: 0 on success
*/
int main(int argc, char **argv)
{
char *input;
int status = 1;

/* Ignore unused argument warnings */
(void)argc;
(void)argv;

signal(SIGINT, handle_sigint);

while (status)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "#cisfun$ ", 9);

input = read_input();
if (!input)
break;

status = execute_command(input);
free(input);
}

return EXIT_SUCCESS;
}

