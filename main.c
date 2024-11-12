#include "main.h"

int main(int ac, char **argv)
{
char *prompt = "(Lash)$";
char *lineptr;
size_t n = 0;
ssize_t n_read;

/*declaring void variables*/
(void)ac; (void)argv;

/*infinite loop for prompt*/
while(1)
{
printf("%s", prompt);
n_read = getline(&lineptr, &n, stdin);
	if(n_read == -1)
	{
		printf("Exiting lash.....\n");
		return(-1);
	}
printf("%s\n", lineptr);

free(lineptr);
}
return (0);
}
