#include "main.h"

void print_error(const char *message)
{
    fprintf(stderr, "Lash: %s\n", message);
}

void print_error_with_arg(const char *message, const char *arg)
{
    fprintf(stderr, "Lash: %s: %s\n", message, arg);
}

void print_system_error(const char *message)
{
    perror(message);
}
