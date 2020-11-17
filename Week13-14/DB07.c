// Kevin A. Roa
// Edited 11/14/2020
// A C program to send user inputted data through a pipe from the parent process to child

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define INPUT_LENGTH 30

int main(void) {
	int pipefd[2];
	char name[INPUT_LENGTH];

	// On error
	if (pipe(pipefd) == -1)
	{
		perror("pipe error");
		exit(1);
	}

	pid_t pid = fork();
	// On error
	if (pid < 0) {
		perror("fork error");
		exit(1);
	}
	// Child process
	else if(pid == 0) {
		// Close the write end of the pipe becuase only reading on child
		close(pipefd[1]);

		pid = getpid();
		// Print child pid before read from pipe
		printf("(%d) Child pid: %d\n", pid, pid);

		// Read from pipe
		read(pipefd[0], name, INPUT_LENGTH);
		printf("(%d) Reading from pipe.\n", pid);
		printf("(%d) Hello %s.\n", pid, name);

		// Print child pid after read from pipe
		// Verify that it stayed the same
		printf("(%d) Child pid: %d\n", getpid(), getpid());
		exit(1);
	}
	// Parent process

	// Close the read end of the pipe becuase only writing on parent
	close(pipefd[0]);

	// Print parent pid before write to pipe
	pid_t ppid = getpid();
	printf("(%d) Parent pid: %d\n", ppid, ppid);
	
	// Sleep for a short period so the pids print next to eachother
	usleep(1000);

	// Prompt user for name
	printf("(%d) Please enter your name: ", ppid);
	scanf("%s", name);

	// Write name to pipe
	printf("(%d) Writing to pipe.\n", ppid);
	write(pipefd[1], name, INPUT_LENGTH);
	printf("(%d) Wrote \"%s\" to pipe.\n", ppid, name);

	// Wait for child to finish
	wait(NULL);

	// Print parent pid after write to pipe
	// Verify that it stayed the same
	printf("(%d) Parent pid: %d\n", getpid(), getpid());

	return 0;
}