#include "shell.h"

int execute_command(char *input)
{
pid_t pid;
int status;

pid = fork();
if (pid == 0)
/* Child process */
{
if (execlp(input, input, NULL) == -1)
{
perror(input);
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

