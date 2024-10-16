#include "main.h"

int (*get_builtin_func(char *command))(char **args)
{
    builtin_t builtins[] = {
        {"exit", lash_exit},
        {"cd", lash_cd},
        {"env", lash_env},
        {NULL, NULL}
    };

    for (int i = 0; builtins[i].name; i++)
    {
        if (strcmp(command, builtins[i].name) == 0)
            return builtins[i].func;
    }
    return NULL;
}

int lash_exit(char **args)
{
    (void)args;
    printf("Exiting Lash...\n");
    exit(EXIT_SUCCESS);
}

int lash_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "lash: cd: missing argument\n");
        return 1;
    }
    if (chdir(args[1]) != 0)
    {
        perror("lash: cd");
        return 1;
    }
    return 0;
}

int lash_env(char **args)
{
    (void)args;
    char **env = environ;
    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
    return 0;
}
