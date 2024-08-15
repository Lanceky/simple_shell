#include "shell.h"

/**
 * read_input - Reads input from the user
 * Return: The input string or NULL on failure
 */
char *read_input(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    nread = getline(&line, &len, stdin);
    if (nread == -1)
    {
        free(line);
        return (NULL);
    }

    /* Remove newline character */
    if (line[nread - 1] == '\n')
        line[nread - 1] = '\0';

    return (line);
}

