#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    char command[100];

    printf("Enter a Linux command: ");
    fgets(command, sizeof(command), stdin);

    command[strcspn(command, "\n")] = '\0';

    if (strlen(command) == 0) {
        printf("No command entered.\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("\nChild Process\n");
        printf("Child PID = %d\n", getpid());
        printf("Child PPID = %d\n", getppid());

        execlp(command, command, (char *)NULL);

        perror("exec failed");
        exit(1);
    }
    else {
        // Parent process
        printf("\nParent Process\n");
        printf("Parent PID = %d\n", getpid());
        printf("Child PID = %d\n", pid);

        wait(NULL);

        printf("Parent: Child process has completed.\n");
    }

    return 0;
}
