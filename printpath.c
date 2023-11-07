#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	char *path = getenv("PATH");

	printf("address of environ is: %p\n", environ);
	printf("address of env is: %p\n", env);

	printf("address of path is: %p\n", path);

	printf("the path variable is: %s\n", path);

	return (0);
}
