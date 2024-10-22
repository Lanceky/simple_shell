#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = "(Lash)$";
	char *lineptr; //stores the address of the buffer holding whatever was typed
	size_t n = 0; //stores allocated size in bytes
	while (1)
	{
	printf("%s", prompt);
	getline(&lineptr, &n, stdin); //the getline function that allows us to get what the user types, stdin is the stream(source keyboard)
	printf("%s", lineptr);

	free(lineptr);
	}
	return (0);
}
