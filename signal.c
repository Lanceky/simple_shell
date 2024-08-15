#include "shell.h"

/**
*handle_sigint - Handles the SIGINT signal (Ctrl+C)
*@sig: Signal number (unused)
*/
void handle_sigint(int sig)
{
(void)sig;
write(STDOUT_FILENO, "\n#cisfun$ ", 9);
}

