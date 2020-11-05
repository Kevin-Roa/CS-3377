// Kevin A. Roa
// Edited 11/4/2020
// A C program to:
//	Demonstrate knowledge on basic multiprocess thread utilization
//	1
//		Write hello world on a child process
// 		Print the ids of the child and parent
//		Catch fork error
//	2
// 		Run fibonacci sequence on child process
//		Make parent wait for child
// 		Print the ids of the child and parent
//		Catch fork error
//	3
//		Use pthreads
// 		print hello world and thread id on n threads

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#define NUM_THREADS 4

void a() {
	pid_t pid = fork();

	// On error
	if (pid < 0)
		// Assignment says to use sys_err but that seems like it is specific to the book
		// Used perror instead because it should do the same thing
		perror("Fork Error");
	// If child process
	else if (pid == 0) {
		puts("Hello, World!");
		exit(1);
	}
	printf("The child and parent process ids are: %d and %d.\n", pid, getpid());
	exit(1);
}

void b() {
	pid_t pid = fork();

	// On error
	if (pid < 0)
		// Assignment says to use sys_err but that seems like it is specific to the book
		// Used perror instead because it should do the same thing
		perror("Fork Error");
	// If child process
	else if (pid == 0)
	{
		int size = 0;
		int valid;
		// Repeatedly ask for user input until valid positive number
		do {
			puts("Enter the number of members in the sequence.");
			scanf("%d", &size);

			// Print on negative number
			if (size <= 0) {
				puts("Enter a positive number.\n");
				valid = 0;
			}
			else
				valid = 1;
		}
		while (valid == 0);

		// Calculate Fibonacci sequence
		double n1 = 0, n2 = 1;
		double temp;
		for (int i = 1; i <= size; i++) {
			printf("%.0f, ", n1);
			temp = n1 + n2;
			n1 = n2;
			n2 = temp;
		}
		puts("");

		exit(1);
	}
	// Wait for child process to finish
	wait(NULL);
	printf("The child and parent process ids are: %d and %d.\n", pid, getpid());
	exit(1);
}

// Print hello world with tid
void* helloWorld() {
	printf("Hello, World! from thread id: %lu\n", (unsigned long) pthread_self());
	pthread_exit(NULL);
}

void c() {
	// Array for holding the pids of new threads
	pthread_t pids[NUM_THREADS];
	// Loop NUM_THREADS times creating new threads
	// Add every new thread pid to array
	for (int i = 0; i < NUM_THREADS; i++)
		pthread_create(&pids[i], NULL, helloWorld, NULL);

	// Wait for all threads to finish before terminating program.
	for (int i = 0; i < NUM_THREADS; i++)
		pthread_join(pids[i], NULL);
	exit(1);
}

// Choose which assignment to run
void getAssignment() {
	int assignment;
	// Prompt for assignment number
	printf("Enter the number for the assignment you want to run.\n(1, 2, 3)\n");
	scanf("%d", &assignment);
	puts("");

	// Run specific assignment
	switch(assignment) {
		case 1:
			a();
			break;
		case 2:
			b();
			break;
		case 3:
			c();
			break;
		default:
			puts("Enter a valid assignment.");
			getAssignment();
	}
}

int main() {
	getAssignment();
	return 0;
}
