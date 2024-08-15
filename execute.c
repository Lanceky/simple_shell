#include "shell.h"

int execute_command(char *input)
{
pid_t pid;
int status;
char *args[1024];
char *token;
int i = 0;

token = strtok(input, " ");
while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, " ");
}
args[i] = NULL;

pid = fork();
if (pid == 0)
/* Child process */
{
if (execvp(args[0], args) == -1)
{
perror(args[0]);
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

