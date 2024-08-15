#include "shell.h"

int execute_input(char *input, char *prog_name)
{
    char *args[1024];
    char *token;
    int i = 0;

    token = strtok(input, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    /* Check for built-in commands like exit */
    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }

    /* Fork and execute */
    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror(prog_name);
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("hsh");
    } else {
        wait(NULL);
    }
    
    return 1;
}

