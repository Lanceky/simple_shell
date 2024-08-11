#include "shell.h"

/**
 * handle_sigchld - Signal handler for SIGCHLD
 * @sig: The signal number
 *
 * This function is used to handle the SIGCHLD signal, which is sent
 * to the process when a child process terminates. It is used to reap
 * the child processes to prevent zombie processes.
 */
void handle_sigchld(int sig)
{
    (void)sig;  // Prevent unused parameter warning
    while (waitpid(-1, NULL, WNOHANG) > 0)
        ;
}

/**
 * execute_command - Executes a command
 * @command: The command string to be executed
 *
 * This function forks a child process to execute the specified command
 * using execvp. If the command fails, an error message is printed.
 */
void execute_command(char *command)
{
    pid_t pid;
    int status;
    char *args[MAX_ARGS];
    int i = 0;

    // Tokenize the command into arguments
    args[i] = strtok(command, " ");
    while (args[i] != NULL && i < MAX_ARGS - 1)
    {
        i++;
        args[i] = strtok(NULL, " ");
    }
    args[i] = NULL;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        execvp(args[0], args);
        perror(args[0]);
        _exit(1);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}

/**
 * print_prompt - Prints the shell prompt
 *
 * This function displays the shell prompt to the user. It helps in
 * indicating that the shell is ready to accept a new command.
 */
void print_prompt(void)
{
    write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
}

/**
 * shell_loop - Main loop of the shell
 *
 * This function contains the main loop of the shell. It continuously
 * reads user input, processes commands, and displays the prompt until
 * the shell is exited.
 */
void shell_loop(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Set up the signal handler for SIGCHLD
    signal(SIGCHLD, handle_sigchld);

    while (1)
    {
        print_prompt();
        read = getline(&line, &len, stdin);
        if (read == -1)
        {
            if (feof(stdin))
            {
                write(STDOUT_FILENO, "\n", 1);
                free(line);
                exit(0);
            }
            perror("getline");
            continue;
        }

        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        execute_command(line);
    }

    free(line);
}

