#include "main.h"
void execmd(char ** argv)
{
char *command = NULL, *actual_command = NULL;
if (argv)
{ 
command = argv[0];
actual_command = get_location(command);
/* execute the actual command with execve*/
actual_command = get_location(comand);
if (execve(actual_command, argv, NULL) == -1)
{
	perror("Error:");
}
}
}

