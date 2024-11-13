#include "main.h"

int main(int ac, char **argv)
{
char *prompt = "(Lash)$";
char *lineptr;
size_t n = 0;
ssize_t n_read;
char *lineptr_copy = NULL;
const char *delim =  "\n";
char *token;
int num_tokens = 0;
int i;

/*declaring void variablesi*/
(void)ac;

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
/*calculate the number of tokens required from the string*/
token = strtok(lineptr, delim);
while (token != NULL)
{
	num_tokens++;
	token = strtok(NULL, delim);
}
num_tokens++;
/*allocate space to hodl the arra of strings (token)*/
argv = malloc(sizeof(char *) * num_tokens);
for(i = 0; token != NULL; i++)
{
	argv[i] = malloc(sizeof(char) * strlen(token));
	strcpy(argv[i], token);

	token = strtok(NULL, delim);
}
argv[i] = NULL;
/*execute the commands with exceve*/

free(lineptr);
free(lineptr_copy);
free(argv);
}
return (0);
}
