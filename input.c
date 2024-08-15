#include "shell.h"

char *read_input(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    nread = getline(&line, &len, stdin);
    if (nread == -1) {
        free(line);
        return NULL;
    }

    /* Remove newline character */
    line[nread - 1] = '\0';
    return line;
}

