#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * read_input - Reads a line of input from the user
 *
 * Return: A string containing the user input
 */
char *read_input(void)
{
    char *input = NULL;
    size_t len = 0;

    if (getline(&input, &len, stdin) == -1)
    {
        free(input);
        return (NULL);
    }
    return (input);
}

/**
 * execute_input - Executes the command given by the user
 * @input: The command to execute
 * @shell_name: The name of the shell (used for error messages)
 *
 * Return: 0 on success, -1 on failure
 */
int execute_input(char *input, char *shell_name)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror(shell_name);
        return (-1);
    }
    if (pid == 0)  // Child process
    {
        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        execlp(input, input, (char *)NULL);
        perror(shell_name);
        exit(EXIT_FAILURE);
    }
    else  // Parent process
    {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
            return (-1);
    }
    return (0);
}

