#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "builtin.h"

int handle_builtin(char *args[]) {

    if (args[0] == NULL) {
        return 1;
    }

    if (strcmp(args[0], "cd") == 0) {

        if (args[1] == NULL) {
            printf("cd: missing argument\n");
        }
        else if (chdir(args[1]) != 0) {
            perror("cd");
        }

        return 1;
    }

    return 0;
}
