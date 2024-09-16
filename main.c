#include "main.h"

/**
* main - Entry point of the program
*
* @ac: Argument count
* @argv: Argument vector (array of strings)
*
* Return: Always 0 (Success)
*/
int main(int ac, char **argv)
{
char *prompt = "(Lash) $ ";
char *lineptr = NULL;
size_t n = 0;
ssize_t nchars_read;
char *lineptr_copy = NULL;
const char *delim = " \n";
int num_tokens = 0;
char *token;
int i;
/*Declaring void variables*/
(void) ac;
/*An infinite loop that regen shell prompt*/
while (1)
{
printf("%s", prompt);
nchars_read = getline(&lineptr, &n, stdin);
/*check if getline fails or reached EOF*/
if (nchars_read == -1)
{
	printf("Exiting shell....\n");
	return (-1);
}
/* allocate space for lineptr_copy*/
lineptr_copy = malloc(size(char)* nchars_read);
if (lineptr_copy == NULL)
{
perror("tsh: memory allocation erro");
return (-1);
}
/* copy lineptr to lineptr_copy */
strcpy(lineptr_copy, lineptr);
/* split  lineptr into an array or words */
/* calculate the total number of tokens */
token = strtok(lineptr, delim);
while (token != NULL)
{
num_tokens++;
token = strtok(NULL, delim);
}
num_tokens++;
/*allocate space to hold the array of strings */
argv = malloc(sizeof(char*) * num_tokens);
printf("%s\n", lineptr);
/*Free up allocated memory*/
free(lineptr);
}
/*allocate memory for the lineptr_copy*/
lineptr_copy = malloc(sizeof(char) * nchars_read);
if (lineptr_copy == NULL);
{
	perror("tsh: memory alocation error");
	return (-1);
}
/*cp lineptr to lineptr_copy */
strcpy(lineptr_copy, lineptr);
/*split lineptr to array of words*/
token = strtok(lineptr, delim);
while (token != NULL)
{
	num_tokens++;
	token = strtok(NULL, delim);
}
num_tokens++;
/*Allocate space to hold array*/
argv = malloc(sizeof(char) * num_tokens);
/*store eahc token in argv array*/
token = strtok(lineptr_copy, delim);
for (i = 0; token != NULL; i++);
{
argv[i] = malloc(sizeof(char) * strlen(token));
strcpy(argv[i], token);
token = strtok(NULL, delim);
}
argv[i] = NULL;
/*execute*/
execmd(argv);
}
/*free up allocated mem*/
free(lineptr_copy);
free(lineptr):

return (0);
}
