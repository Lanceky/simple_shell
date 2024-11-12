#include "main.h"

int main(int ac, char **argv)
{
char *prompt = "(Lash)$";
char *lineptr;
size_t n = 0;
ssize_t n_read;
char *lineptr_copy = NULL;
const char *delim =  "\n";
/*declaring void variablesi*/
(void)ac; (void)argv;

/*infinite loop for prompt*/
while(1)
{
printf("%s", prompt);
n_read = getline(&lineptr, &n, stdin);
	if(n_read == -1)
	{
		printf("Exiting lash....\n");
		return(-1);
	}
printf("%s\n", lineptr);
/*allocate space to lineptr and copy lineptr to lineptr_copy*/
lineptr_copy = malloc(sizeof(char) * n_read);
if(lineptr_copy == NULL){
	perror("tsh: error allcoating memory");
	return(-1);
}
strcpy(lineptr_copy, lineptr);
free(lineptr);
}
return (0);
}
