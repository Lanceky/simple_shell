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
char *lineptr;
size_t n = 0;
ssize_t nchars_read;
/*Declaring void variables*/
(void) ac;
(void) argv;
/*An infinite loop*/
while (1)
{
printf("%s", prompt);
nchars_read = getline(&lineptr, &n, stdin);
if (nchars_read == -1)
{
	printf("Exiting shell....\n");
	return (-1);
}
printf("%s\n", lineptr);

free(lineptr);
}
return (0);
}

