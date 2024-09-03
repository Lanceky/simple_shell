#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;  // To use the global environ variable

void display_prompt(void);  // Function prototype
void handle_input(char *line);  // Function prototype

/**
 * main - Entry point for the shell program.
 * Return: 0 on success.
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;

    while (1)
    {
        display_prompt();  // Display the prompt
        if (getline(&line, &len, stdin) == -1)
        {
            perror("getline");
            free(line);
            exit(EXIT_FAILURE);
        }

        // Remove newline character from the input line
        line[strcspn(line, "\n")] = '\0';

        if (line[0] != '\0')  // Check if line is not empty
        {
            handle_input(line);
        }
    }

    free(line);
    return 0;
}

/**
 * display_prompt - Prints the shell prompt.
 */
void display_prompt(void)
{
    printf("#cisfun$ ");
    fflush(stdout);
}

/**
 * handle_input - Handles user input, executing commands.
 * @line: Pointer to the user input line.
 */
void handle_input(char *line)
{
    pid_t pid;
    int status;
    char *argv[] = {line, NULL};  // Create argv array

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        if (execve(line, argv, environ) == -1)
        {
            perror(line);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}
