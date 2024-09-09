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
/*Declaring void variables*/
(void)ac; (void)argv;
/*An infinite loop*/
while(1)
{
printf("%s", prompt);
getline(&lineptr, &n, stdin);
printf("%s\n", lineptr);

free(lineptr);
}
return (0);
}

