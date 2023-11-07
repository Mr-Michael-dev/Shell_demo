#include <stdio.h>
#include <string.h>

extern char **environ;

void *_getenv(const char *name)
{
	int i;
	char *token;

	for (i = 0; environ[i] != NULL; i++)
	{
		token = strtok(environ[i], "=");

		if (token == NULL)
		{
			continue;
		}

		if (strcmp(name, token) == 0)
		{
			token = strtok(NULL, " \n");
			return (token);
		}
	}
		
		return (NULL);

}


int main(int ac, char **av, char **env)
{
        char *path = _getenv("PATH");

        printf("address of environ is: %p\n", environ);                                                     printf("address of env is: %p\n", env);                                                             printf("address of path is: %p\n", path);

        printf("the path variable is: %s\n", path);
                                                          return (0);
}
