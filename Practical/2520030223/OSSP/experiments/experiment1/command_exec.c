#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    char command[100];
    pid_t pid;
    int status;

    printf("Enter a Linux command: ");
    scanf("%99s", command);

    printf("Parent Process PID: %d\n", getpid());

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("Child Process PID: %d\n", getpid());
        printf("Child PPID: %d\n", getppid());
        printf("Executing command: %s\n", command);

        execlp(command, command, (char *)NULL);

        perror("exec failed");
        exit(1);
    } 
    else {
        printf("Parent waiting for child...\n");

        wait(&status);

        printf("Child process %d has completed.\n", pid);
        printf("Parent process continuing.\n");
    }

    return 0;
}
