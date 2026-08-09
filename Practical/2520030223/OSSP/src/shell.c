#include <stdio.h>
#include <string.h>
#include "shell.h"
#include "parser.h"
#include "executor.h"
#include "builtin.h"

void start_shell() {
    char command[100];
    char *args[MAX_ARGS];

    while (1) {
        printf("my_shell> ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }

        if (strlen(command) == 0) {
            continue;
        }

        parse_command(command, args);

        if (!handle_builtin(args)) {
            execute_command(args);
        }
    }
}
