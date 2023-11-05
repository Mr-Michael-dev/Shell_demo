#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char* line = NULL;
	size_t len = 0;
	ssize_t read;
	char *del = " ";
	char *arg[10];
	size_t i = 0;
	size_t j;
	char *token;
	char *line_cpy;

	printf("#cisfun:$ ");


	while ((read = getline(&line, &len, stdin)) != EOF)
	{
		printf("entered line: %s", line);
		line_cpy = line;
		token = strtok(line_cpy, del);
		while (token != NULL && i < 10)
		{
			arg[i++] = token;
			token = strtok(NULL, del);
		}
		printf("arguments: \n");
		for (j = 0; j < i; j++)
		{
			printf("%s\n", arg[j]);
		}

		i = 0;
		printf("#cisfun:$ ");
		free(line);
		len = 0;
		line = NULL;

	}
	free(line);
	printf("\n");
	return (0);
}
