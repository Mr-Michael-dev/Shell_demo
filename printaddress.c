#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	printf("address of environ is %p\n", environ);
	printf("address of env is %p\n", env);

	return (0);
}
