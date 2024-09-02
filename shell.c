#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    pid_t pid;
    char *argv[] = {NULL, NULL};

    while (1)
    {
        printf("$ ");
        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            free(line);
            exit(EXIT_SUCCESS);
        }
        line[nread - 1] = '\0';  // Remove newline character
        argv[0] = line;
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {
            // Child process
            if (execve(argv[0], argv, NULL) == -1)
            {
                perror("./hsh");
            }
            exit(EXIT_FAILURE);
        }
        else
        {
            // Parent process
            wait(NULL);
        }
    }
    return (0);
}

