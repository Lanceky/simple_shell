#include "shell.h"

/* Function prototypes */
char *read_input(void);
int execute_input(char *input, char *shell_name);
void handle_sigint(int sig);

/**
*main - Entry point of the shell
*@argc: Argument count (unused)
*@argv: Argument vector (used to get shell name)
*Return: 0 on success
*/
int main(int argc, char **argv)
{
char *input;
int status = 1;

/* Ignore unused argument warnings */
(void)argc;

/* Set signal handler for SIGINT */
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

return EXIT_SUCCESS;
}

