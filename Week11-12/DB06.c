#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// Example function for different processes to run
void example()
{
	printf("Running example function on process id %d\n", getpid());
}

int main(int argc, char const *argv[])
{
	// Create new process
	pid_t pid = fork();

	// If error in creating new process
	if (pid < 0)
		printf("Error");
	// Run on child process
	else if (pid == 0) {
		printf("Child: ");
		example();
		exit(0);
	}
	// Run on parent process
	// Wait for child process to complete before continuing
	waitpid(pid, NULL, 0);
	printf("Parent: ");
	example();
}
