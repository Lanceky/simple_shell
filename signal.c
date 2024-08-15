#include "shell.h"

/**
 * handle_sigint - Handles the SIGINT signal (Ctrl+C)
 * @sig: The signal number
 */
void handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n#cisfun$ ", 9);
}

