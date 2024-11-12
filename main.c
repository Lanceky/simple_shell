#include "main.h"

int main(int ac, char **argv)
{
char *prompt = "(Lash)$";
char *lineptr;
size_t n = 0;

/*declaring void variables*/
(void)ac; (void)argv;

/*infinite loop for prompt*/
while(1)
{
printf("%s", prompt);
getline(&lineptr, &n, stdin);
printf("%s\n", lineptr);

free(lineptr);
}
return (0);
}
