char *_getenv(const char *env_var)
{
    extern char **environ;
    int i = 0;
    char *key;

    while (environ[i])
    {
        key = strtok(environ[i], "=");
        if (strcmp(key, env_var) == 0)
            return (strtok(NULL, "="));
        i++;
    }
    return (NULL);
}
