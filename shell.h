#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROMPT "$ "
#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 100

void handle_sigchld(int sig);
void execute_command(char *command);
void print_prompt(void);
void shell_loop(void);

#endif /* SHELL_H */

