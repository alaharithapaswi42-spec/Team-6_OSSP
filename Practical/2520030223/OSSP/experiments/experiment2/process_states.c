#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("Parent Process Started\n");
    printf("Parent PID  : %d\n", getpid());
    printf("Parent PPID : %d\n", getppid());
    printf("Parent State: Running\n\n");

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        /* Child process */

        printf("Child Process Created\n");
        printf("Child PID   : %d\n", getpid());
        printf("Child PPID  : %d\n", getppid());
        printf("Child State : Running\n");

        printf("Child State : Waiting\n");
        sleep(10);

        printf("Child State : Running\n");

        printf("Child Process Terminating\n");

        exit(0);
    }
    else {
        /* Parent process */

        printf("Parent PID  : %d\n", getpid());
        printf("Child PID   : %d\n", pid);
        printf("Parent State: Running\n");

        printf("Parent State: Waiting for child\n");

        wait(NULL);

        printf("Parent State: Running\n");
        printf("Child Process has Terminated\n");

        printf("Parent Process Terminating\n");
    }

    return 0;
}
