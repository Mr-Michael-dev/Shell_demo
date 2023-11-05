#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	char *argv[]= {"/bin/ls", "-l", NULL};
	pid_t cpid;
	int i = 0;

	while (i < 5)
	{
		cpid = fork();

		if (cpid == -1)
		{
			perror("Fork failed");
			return (-1);
		}

		if (cpid == 0)
		{
			if ((execve(argv[0], argv, NULL)) == -1)
			{
				perror("Execution failed");
			}
		}
		else
		{
			wait(NULL);
		}

		i++;
	}

	return (0);
}
