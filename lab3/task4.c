#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to calculate the factorial of a given number
int factorial(int n) {
    int result = 1;
    int i;
    // TODO: Implement the factorial function
    for (i = 1; i <= n; ++i) {
            result *= i;
    }   
    return result;
}

int main() {
    int N, i;
    printf("Enter the number of child processes to create: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            // Fork failed
            printf("Fork failed for child %d\n", i);
            exit(1);
        } else if (pid == 0) {
            // Child process
            printf("Child process with PID: %d and Parent PID: %d\n", getpid(), getppid());
            int result = factorial(i + 1); // Example calculation input
            // TODO: Print the result
            printf("Result is: %d\n", result);
            exit(0); // Child process ends
        } else {
            // Parent process
            // TODO: Print appropriate message indicating the creation of a child process
            printf("Child %d process created\n", i);
        }

    }

    // TODO: Write a loop to wait for all child processes
    for (i = 0; i < N; i++) {
        wait(NULL);
    }
    printf("All children have terminated. Parent process exiting.\n");
    return 0;
}