#include "shell.h"

void handle_sigint(int sig)
{
(void)sig;
write(STDOUT_FILENO, "\n#cisfun$ ", 9);
}

