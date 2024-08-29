#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64

extern char **environ;

char *search_path(char *cmd)
{
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");
    char full_path[MAX_CMD_LEN];

    while (dir != NULL) {
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, cmd);
        if (access(full_path, X_OK) == 0) {
            free(path_copy);
            return strdup(full_path);
        }
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}

int main(void)
{
    char *cmd = NULL;
    size_t cmd_size = 0;
    ssize_t chars_read;
    char *args[MAX_ARGS];
    int arg_count;

    while (1) {
        printf("#cisfun$ ");
        chars_read = getline(&cmd, &cmd_size, stdin);

        if (chars_read == -1) {
            printf("\n");
            break;  // Handle EOF (Ctrl+D)
        }

        cmd[strcspn(cmd, "\n")] = 0;  // Remove newline

        // Tokenize input
        arg_count = 0;
        args[arg_count] = strtok(cmd, " ");
        while (args[arg_count] != NULL && arg_count < MAX_ARGS - 1) {
            arg_count++;
            args[arg_count] = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        if (arg_count > 0) {
            char *cmd_path = search_path(args[0]);
            if (cmd_path != NULL) {
                pid_t pid = fork();
                if (pid == 0) {
                    // Child process
                    execve(cmd_path, args, environ);
                    perror("./shell");
                    exit(1);
                } else if (pid > 0) {
                    // Parent process
                    wait(NULL);
                } else {
                    perror("fork");
                }
                free(cmd_path);
            } else {
                printf("./shell: No such file or directory\n");
            }
        }
    }

    free(cmd);
    return 0;
}
