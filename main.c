#include "shell.h"

int main(int argc, char **argv)
{
    char *input;
    int status = 1;

    signal(SIGINT, handle_sigint);

    while (status) {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "hsh$ ", 5);

        input = read_input();
        if (!input)
            break;

        status = execute_input(input, argv[0]);
        free(input);
    }

    return EXIT_SUCCESS;
}

