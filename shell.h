#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/* Function prototypes */
char *read_input(void);
int execute_command(char *input);
void handle_sigint(int sig);

#endif /* SHELL_H */

