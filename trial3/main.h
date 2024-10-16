#ifndef MAIN_H
#define MAIN_H
#include <stdio.h> /*for input and output operations like printf*/
#include <stdlib.h> /* for general utilities like malloc and free*/
#include <string.h> /* for string maninputlation lkke strcpy*/
#include <unistd.h> /* for unix standard functions like execve*/
#include <sys/types.h> /*for stat funciton ot check the file status*/
#include <sys/wait.h> /*  C provides macros and functions that allow a parent process to wait for and retrieve the termination status of its child processes. */

#define PROMPT "$Lash" /*shell prompt display*/
/*function prototypes*/
void display_prompt(void);
void *read_input(void);
void execute_command(char *command);
void free_input(char *command);
void free_input(char *input);

#endif /* MAIN */
