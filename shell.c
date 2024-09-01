#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80 // Max command length

void parseInput(char *input, char **args) {
    for (int i = 0; i < MAX_LINE / 2 + 1; i++) {
        args[i] = strsep(&input, " \t\n");
        if (args[i] == NULL) break;
    }
}

int main() {
    char *args[MAX_LINE/2 + 1];
    char input[MAX_LINE];
    pid_t pid;
    int should_run = 1;

    while (should_run) {
        printf("myshell> ");
        fflush(stdout);
        
        if (fgets(input, MAX_LINE, stdin) == NULL) {
            perror("fgets failed");
            exit(1);
        }
        
        parseInput(input, args);
        
        if (args[0] == NULL) continue; // Empty command
        
        if (strcmp(args[0], "exit") == 0) {
            should_run = 0;
            continue;
        }

        pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            if (execvp(args[0], args) < 0) {
                perror("Exec failed");
                exit(1);
            }
        } else {
            wait(NULL);
        }
    }
    
    return 0;
}

