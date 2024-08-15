#include "shell.h"

/**
*execute_input - Executes the input command
*@input: Command input from the user
*@shell_name: The name of the shell (used for error messages)
*Return: 1 to continue running the shell, 0 to exit
*/
int execute_input(char *input, char *shell_name)
{
pid_t pid;
int status;

pid = fork();
if (pid == 0)
/* Child process */
{
if (execlp(input, input, NULL) == -1)
{
perror(shell_name);
exit(EXIT_FAILURE);
}
}
else if (pid < 0)
{
perror("fork");
return 1;
}
else
/* Parent process */
{
waitpid(pid, &status, 0);
}

return 1;
}

