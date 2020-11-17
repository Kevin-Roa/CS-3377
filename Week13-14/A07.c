// Kevin A. Roa
// Edited 11/16/2020
// A C program to:
//	Demonstrate knowledge on basic multiprocess thread utilization
//	1
//		Use pthreads
// 		print hello world and thread id on n threads
//	2
// 		Run fibonacci sequence on 2 child processes
//		1 child returns creates array of all values in sequence
//		1 child gets sum of all values in sequence
//		Make parent wait for children
// 		Print the ids of the new processes
//		This is not very efficient 

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_FIB 40

unsigned int sum, values[MAX_FIB];

// Print hello world with tid
void *helloWorld()
{
	printf("Hello, World! from thread id: %lu\n", (unsigned long) pthread_self());
	pthread_exit(NULL);
}

void a()
{
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

void* getFibSeq(void *size) {
	printf("Thread %lu Starting.\n", (unsigned long) pthread_self());
	// Calculate Fibonacci sequence
	double n1 = 0, n2 = 1;
	double temp; 
	for (int i = 1; i <= (int) size; i++)
	{
		// Store value in values array
		values[i-1] = n1;

		temp = n1 + n2;
		n1 = n2;
		n2 = temp;
	}
	printf("Thread %lu Finished.\n", (unsigned long) pthread_self());
	pthread_exit(NULL);
}

void* getFibSum(void *size) {
	printf("Thread %lu Starting.\n", (unsigned long) pthread_self());
	// Calculate Fibonacci sequence
	double n1 = 0, n2 = 1;
	double temp;
	for (int i = 1; i <= (int) size; i++)
	{
		// Add value to sum
		sum += n1;

		temp = n1 + n2;
		n1 = n2;
		n2 = temp;
	}
	printf("Thread %lu Finished.\n", (unsigned long) pthread_self());
	pthread_exit(NULL);
}

void b()
{
	int size = 0;
	int valid;
	// Repeatedly ask for user input until valid positive number
	do
	{
		puts("Enter the number of members in the sequence.");
		scanf("%d", &size);

		// Print on negative number
		if (size <= 0)
		{
			puts("Enter a positive number.\n");
			valid = 0;
		}
		//Print on large number
		else if (size > MAX_FIB)
		{
			printf("Enter a number less than %d.\n", MAX_FIB);
			valid = 0;
		}
		else
			valid = 1;
	} while (valid == 0);
	puts("");

	// Array for holding the pids of new threads
	pthread_t pids[2];

	// Create new threads, add pids to array
	pthread_create(&pids[0], NULL, getFibSum, (void *) size);
	pthread_create(&pids[1], NULL, getFibSeq, (void *) size);

	// Wait for threads to finish
	pthread_join(pids[0], NULL);
	pthread_join(pids[1], NULL);

	// Print data
	printf("\nThe sum of the first %d numbers is: %d\n", size, sum);
	printf("The first %d numbers in the fibonacci sequence are: ", size);
	for (int i = 0; i < size; i++) {
		if (i == size - 1)
			printf("%d\n", values[i]);
		else
			printf("%d, ", values[i]);
	}

	exit(1);
}

// Choose which assignment to run
void getAssignment()
{
	int assignment;
	// Prompt for assignment number
	printf("Enter the number for the assignment you want to run.\n(1, 2)\n");
	scanf("%d", &assignment);
	puts("");

	// Run specific assignment
	switch (assignment)
	{
	case 1:
		a();
		break;
	case 2:
		b();
		break;
	default:
		puts("Enter a valid assignment.");
		getAssignment();
	}
}

int main()
{
	getAssignment();
	return 0;
}
