#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

void prompt(void);
void exec_cmd(char **args);

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *argv[BUFFER_SIZE];
    char *token;
    int i;

    while (1)
    {
        prompt();

        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            if (feof(stdin))
                break; // Handle Ctrl+D
            perror("getline");
            continue;
        }

        // Tokenize input
        i = 0;
        token = strtok(line, " \n");
        while (token != NULL)
        {
            argv[i++] = token;
            token = strtok(NULL, " \n");
        }
        argv[i] = NULL;

        if (argv[0] != NULL)
            exec_cmd(argv);
    }

    free(line);
    return 0;
}

void prompt(void)
{
    printf("#cisfun$ ");
}

void exec_cmd(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // Child process
        if (execve(args[0], args, NULL) == -1)
        {
            perror(args[0]);
        }
        exit(EXIT_FAILURE);
    }
    else
    {
        // Parent process
        wait(&status);
    }
}
