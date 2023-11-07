#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		printf("%s\n", environ[i]);
}
