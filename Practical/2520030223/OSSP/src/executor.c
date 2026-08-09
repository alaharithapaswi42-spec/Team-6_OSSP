#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "executor.h"

void execute_command(char *args[]) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return;
    }

    if (pid == 0) {
        // Child process
        execvp(args[0], args);

        // Only reached if execvp fails
        perror("execvp");
        exit(1);
    }
    else {
        // Parent process
        wait(NULL);
    }
}
