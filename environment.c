#include "main.h"

char *get_env_value(const char *name)
{
    char **env;
    size_t namelen = strlen(name);

    for (env = environ; *env != NULL; env++)
    {
        if (strncmp(*env, name, namelen) == 0 && (*env)[namelen] == '=')
        {
            return &(*env)[namelen + 1];
        }
    }
    return NULL;
}

int set_env_value(const char *name, const char *value)
{
    char *new_var;
    size_t varlen;

    varlen = strlen(name) + strlen(value) + 2;
    new_var = malloc(varlen);
    if (!new_var)
        return -1;

    snprintf(new_var, varlen, "%s=%s", name, value);
    return (putenv(new_var) == 0) ? 0 : -1;
}

int unset_env_value(const char *name)
{
    return unsetenv(name);
}
