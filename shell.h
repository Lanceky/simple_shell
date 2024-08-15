#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

/* Function prototypes */
char *read_input(void);
int execute_input(char *input, char *prog_name);
void handle_sigint(int sig);

#endif /* SHELL_H */
