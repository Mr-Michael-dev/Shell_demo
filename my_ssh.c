#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *del = " \n";
	char *arg[10];
	size_t i = 0;
	char *token;
	char *line_cpy;
	pid_t cpid;

	printf("#cisfun:$ ");


	while ((read = getline(&line, &len, stdin)) != EOF)
	{
		line_cpy = strdup(line);
		token = strtok(line_cpy, del);
		while (token != NULL && i < 10)
		{
			arg[i++] = token;
			token = strtok(NULL, del);
		}

		cpid = fork();
		if (cpid == -1)
		{
			perror("Error occured");
		}
		if (cpid == 0)
		{
			if ((execve(arg[0], arg, NULL)) == -1)
			{
				perror("Execution Failed");
			}
		}
		else
		{
			wait(NULL);
		}

		printf("#cisfun:$ ");
		free(line);
		free(line_cpy);
		len = 0;
		line = NULL;
		i = 0;

	}
	free(line);
	printf("\n");
	return (0);
}
