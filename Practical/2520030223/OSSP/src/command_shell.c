#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char command[100];

    while (1) {
        printf("my_shell> ");
        fgets(command, sizeof(command), stdin);

        // Remove newline
        command[strcspn(command, "\n")] = '\0';

        // Exit command
        if (strcmp(command, "exit") == 0) {
            break;
        }

        pid_t pid = fork();

        if (pid < 0) {
            printf("Fork failed!\n");
        }
        else if (pid == 0) {
            // Child process
            execlp(command, command, NULL);

            // Runs only if exec fails
            printf("Command not found!\n");
            exit(1);
        }
        else {
            // Parent process
            wait(NULL);
        }
    }

    return 0;
}
