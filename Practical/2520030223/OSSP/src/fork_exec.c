#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
    }
    else if (pid == 0) {
        // Child process
        printf("Child process created.\n");
        printf("Executing ls command...\n");

        execlp("ls", "ls", "-l", NULL);

        // This runs only if exec fails
        printf("Exec failed!\n");
    }
    else {
        // Parent process
        wait(NULL);
        printf("Parent process finished.\n");
    }

    return 0;
}
