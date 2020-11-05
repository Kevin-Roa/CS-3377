// This was just me playing around with creating new processes
// It creates PROCESS_COUNT processes that are a child of the main process
// Each process runs concurrently and completes the task
// The main parent process waits for all of the processes to complete
// Each time a process finishes the parent process prints the % completion
// Added colors to printout to better see what's going on

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define PROCESS_COUNT 10

// Random task that child processes need to complete
void task() {
	srand(getpid());

	for (int i = 0; i <= 4; i++) {
		sleep(rand() % 4);
		printf("%d: %d%%\n", getpid(), i * 25);
	}
}

int main() {
	// Create PROCESS_COUNT new processes
	for (int i = 0; i < PROCESS_COUNT; i++) {
		pid_t pid = fork();

		if (pid < 0) {
			perror("\x1b[1;31mError\x1b[0m");
		}
		// Child process
		// If successfully created new process, run task on new child
		else if (pid == 0) {
			printf("\x1b[33mStarting new process (%d)...\x1b[0m\n", getpid());
			task();
			exit(0);
		}
	}

	// Parent Process
	int completed = 0;
	// Detect every time a child process completes the task
	for (int i = 0; i < PROCESS_COUNT; i++) {
		wait(NULL);
		completed += 1;
		//Print % completion
		printf("\x1b[1;32m%.0f%% Complete\x1b[0m\n", (double)completed / PROCESS_COUNT * 100);
	}
	puts("\x1b[1;36mAll threads completed task.");

	return 0;
}
