#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *helloWorld()
{
	printf("Hello World! from thread id: %lu (Pthread process)\n", (unsigned long)pthread_self());
	pthread_exit(NULL);
}

int main()
{
	pid_t pid = fork();

	// On error
	if (pid < 0)
	{
		perror("Fork Error");
		exit(1);
	}
	// If child process
	else if (pid == 0)
	{
		pthread_t pid2;
		pthread_create(&pid2, NULL, helloWorld, NULL);
		pthread_join(pid2, NULL);

		pid_t pid3 = fork();
		// On error
		if (pid3 < 0)
		{
			perror("Fork Error");
			exit(1);
		}
		// If sub child process
		else if (pid3 == 0)
		{
			printf("Hello World! from thread id: %lu (Inner child process)\n", (unsigned long)getpid());
			return 0;
		}
		// Main child process
		wait(NULL);
		return 0;
	}
	// Parent process
	wait(NULL);
	exit(1);
}
